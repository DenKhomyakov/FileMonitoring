#include "FileMonitoring.h"
#include "Logger.h"

FileMonitoring::FileMonitoring() {
    logger = new Logger();
    connect(this, &FileMonitoring::initialFileInfo, logger, &Logger::printInitialFileInfo);
    connect(this, &FileMonitoring::fileExistsAndModified, logger, &Logger::printFileExistsAndModified);
    connect(this, &FileMonitoring::fileExistsAndNotModified, logger, &Logger::printFileExistsAndNotModified);
    connect(this, &FileMonitoring::fileNotExists, logger, &Logger::printFileNotExists);
    connect(this, &FileMonitoring::fileReturned, logger, &Logger::printFileReturned);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &FileMonitoring::checkFileStatus);
    timer->start();
}

FileMonitoring::~FileMonitoring() {
    delete logger;
}

void FileMonitoring::addFile(const QString& path) {
    File file(path);
    file.setInfo(QFileInfo(path));

    if (file.getFileInfo().isFile()) {
        emit initialFileInfo(&file);
    } else {
        emit fileNotExists(file.getFilePath());
    }

    repository.push_back(file);
}

void FileMonitoring::removeFile(const QString& path) {
    int index = -1;

    for (int i = 0; i < repository.size(); ++i) {
        if (repository[i].getFilePath() == path) {
            index = i;

            break;
        }
    }

    repository.removeAt(index);
}

void FileMonitoring::removeFile(const File& file) {
    if (repository.isEmpty()) {
        return;
    }

    repository.removeOne(file);             // Using compare operator
}

void FileMonitoring::checkFileStatus() {
    for (auto& it : repository) {
        QFileInfo updatedFileInfo(it.getFilePath());

        if (!updatedFileInfo.isFile()) {
            if (!it.isRemoved()) {
                emit fileNotExists(it.getFilePath());

                it.setRemoved(true);
            }
        } else {
            if (it.isRemoved()) {
                emit fileReturned(&it);

                it.setRemoved(false);
                it.setFileModifiedShown(false);
                it.setFileNotModifiedShown(false);
            }

            if (updatedFileInfo.lastModified() == it.getTimeChanging()) {
                if (!it.isFileModifiedShown() && !it.isFileNotModifiedShown()) {
                    emit fileExistsAndNotModified(&it);

                    it.setFileNotModifiedShown(true);
                }
            }

            if (updatedFileInfo.lastModified() != it.getTimeChanging()) {
                it.setInfo(updatedFileInfo);

                emit fileExistsAndModified(&it);

                it.setFileModifiedShown(true);
                it.setFileNotModifiedShown(false);
            }
        }
    }
}
