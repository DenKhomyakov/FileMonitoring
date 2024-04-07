#include "FileMonitoring.h"
#include <QDateTime>

FileMonitoring::FileMonitoring(const QString& filePath) : QFileInfo(filePath) {
    this->filePath = filePath;
    fileInfo = QFileInfo(filePath);

    if (fileInfo.isFile()) {
        qDebug() << "File name: " << fileInfo.fileName();
        qDebug() << "File path: " << filePath;
        qDebug() <<  "File size: " << fileInfo.size();
        qDebug() << "Date and time of creation: " <<  fileInfo.birthTime();
    } else {
        qDebug() << "Error: The file was not found in the specified path";
    }
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
    QFileInfo updatedFileInfo(filePath);

    if (!updatedFileInfo.isFile()) {
        qDebug() << "Error: The file does not exist";
    } else if (updatedFileInfo.lastModified() == fileInfo.lastModified()) {
        qDebug() << "File exists and has not been modified";
        qDebug() << "File size: " << getFileSize();
    } else if (updatedFileInfo.lastModified() != fileInfo.lastModified()) {
        qDebug() << "File exists and has been modified";
        qDebug() << "File size: " << getFileSize();
    }
}
