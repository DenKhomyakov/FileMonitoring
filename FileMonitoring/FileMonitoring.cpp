#include "FileMonitoring.h"
#include <QDateTime>

FileMonitoring::FileMonitoring(const QString& filePath, QObject *parent) : QObject(parent) {
    this->filePath = filePath;
    fileInfo = QFileInfo(filePath);

    watcher = new QFileSystemWatcher(this);
    watcher->addPath(filePath);

    if (fileInfo.isFile()) {
        qDebug() << "File name: " << getFileName();
        qDebug() << "File path: " << getFilePath();
        qDebug() <<  "File size: " << getFileSize();
        qDebug() << "Date and time of creation: " <<  fileInfo.birthTime();
    } else {
        qDebug() << "Error: The file was not found in the specified path";
    }

    connect(watcher, &::QFileSystemWatcher::fileChanged, this, &FileMonitoring::HandleFileChanged);
}

QString FileMonitoring::getFilePath() {
    return filePath;
}

QFileInfo FileMonitoring::getFileName() const {
    return fileInfo.fileName();
}

qint64 FileMonitoring::getFileSize() const {
    return fileInfo.size();
}

QDateTime FileMonitoring::getTimeChanging() {
    return fileInfo.lastModified();
}

void FileMonitoring::CheckFileStatus() {
    QFileInfo updatedFileInfo = filePath;

    if (!updatedFileInfo.isFile()) {
        qDebug() << "Error: The file does not exist";
    } else if (updatedFileInfo.lastModified() == fileInfo.lastModified()) {
        qDebug() << "File exists and has not been modified";
        qDebug() << "File size: " << getFileSize();
    } else if (updatedFileInfo.lastModified() != fileInfo.lastModified()) {
        qDebug() << "File exists and has been modified";
        qDebug() << "File size: " << getFileSize();

        fileInfo = updatedFileInfo;

        emit FileChanged();
    }
}

void FileMonitoring::HandleFileChanged() {
    qDebug() << "File has been modified";
}
