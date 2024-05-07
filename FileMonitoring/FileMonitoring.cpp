#include "FileMonitoring.h"
#include "Logger.h"

FileMonitoring::FileMonitoring(const QString& filePath) {
    this->filePath = filePath;
    fileInfo = QFileInfo(filePath);

    fileRemoved = false;

    firstInfoMessageShown = false;
    fileChangedShown = false;
    fileNotChangedShown = false;

    Logger* logger = new Logger();
    connect(this, &FileMonitoring::initialFileInfo, logger, &Logger::printInitialFileInfo);
    connect(this, &FileMonitoring::fileExistsAndModified, logger, &Logger::printFileExistsAndModified);
    connect(this, &FileMonitoring::fileExistsAndNotModified, logger, &Logger::printFileExistsAndNotModified);
    connect(this, &FileMonitoring::fileNotExists, logger, &Logger::printFileNotExists);
    connect(this, &FileMonitoring::fileReturned, logger, &Logger::printFileReturned);

    if (fileInfo.isFile()) {
        emit initialFileInfo(this);

        firstInfoMessageShown = true;
    } else {
        emit fileNotExists();
    }

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &FileMonitoring::checkFileStatus);
    timer->start();
}

QString FileMonitoring::getFilePath() const {
    return filePath;
}

QString FileMonitoring::getFileName() const {
    return fileInfo.fileName();
}

QString FileMonitoring::getFileSize() const {
    qint64 size = fileInfo.size();
    QString unit;

    if (size >= 1024 * 1024 * 1024) {
        size /= 1024 * 1024 * 1024;
        unit = "GB";
    } else if (size >= 1024 * 1024) {
        size /= 1024 * 1024;
        unit = "MB";
    } else if (size >= 1024) {
        size /= 1024;
        unit = "KB";
    } else {
        unit = "B";
    }

    return QString("%1 %2").arg(size).arg(unit);
}

QDateTime FileMonitoring::getTimeChanging() const {
    return fileInfo.lastModified();
}

QDateTime FileMonitoring::getFileBirthTime() const {
    return fileInfo.birthTime();
}

void FileMonitoring::checkFileStatus() {
    QFileInfo updatedFileInfo = filePath;

    if (!updatedFileInfo.isFile()) {
        if (!fileRemoved) {
            emit fileNotExists();

            fileRemoved = true;
        }
    } else {
        if (fileRemoved) {
            emit fileReturned(this);

            fileRemoved = false;
            fileChangedShown = false;
            fileNotChangedShown = false;
        }

        if (updatedFileInfo.lastModified() == fileInfo.lastModified()) {
            if (firstInfoMessageShown && !fileChangedShown && !fileNotChangedShown) {
                emit fileExistsAndNotModified(this);

                fileNotChangedShown = true;
            }
        }

        if (updatedFileInfo.lastModified() != fileInfo.lastModified()) {
            emit fileExistsAndModified(this);

            fileInfo = updatedFileInfo;

            fileChangedShown = true;
            fileNotChangedShown = false;
        }
    }
}
