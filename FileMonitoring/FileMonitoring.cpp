#include "FileMonitoring.h"
#include "Logger.h"

FileMonitoring::FileMonitoring(const QString& filePath, QObject *parent) : QObject(parent) {
    this->filePath = filePath;
    fileInfo = QFileInfo(filePath);

    fileRemoved = false;

    firstInfoMessageShown = false;
    fileChangedShown = false;
    fileNotChangedShown = false;

    if (fileInfo.isFile()) {
        Logger::loggerInfo("File name: " + getFileName());
        Logger::loggerInfo("File path: " + getFilePath());
        Logger::loggerInfo("File size: " + getFileSize());
        Logger::loggerInfo("Date and time of creation: " + getFileBirthTime().toString());

        firstInfoMessageShown = true;
    } else {
        Logger::loggerError("The file was not found in the specified path");
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
            Logger::loggerError("The file does not exist");

            fileRemoved = true;
        }
    } else {
        if (fileRemoved) {
            Logger::loggerInfo("File has been detected");
            Logger::loggerInfo("File size: " + getFileSize());

            emit fileReturned();

            fileRemoved = false;
            fileChangedShown = false;
            fileNotChangedShown = false;
        }

        if (updatedFileInfo.lastModified() == fileInfo.lastModified()) {
            if (firstInfoMessageShown && !fileChangedShown && !fileNotChangedShown) {
                Logger::loggerInfo("File exists and has not been modified");
                Logger::loggerInfo("File size: " + getFileSize());

                emit fileNotChanged();

                fileNotChangedShown = true;
            }
        }

        if (updatedFileInfo.lastModified() != fileInfo.lastModified()) {
            Logger::loggerInfo("File exists and has been modified");
            Logger::loggerInfo("File size: " + getFileSize());

            fileInfo = updatedFileInfo;

            emit fileChanged();

            fileChangedShown = true;
            fileNotChangedShown = false;
        }
    }
}
