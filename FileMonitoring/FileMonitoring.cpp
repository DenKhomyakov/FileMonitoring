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
        qDebug() << "Date and time of creation: " << getFileBirthTime();
    } else {
        qDebug() << "Error: The file was not found in the specified path";
    }

    connect(this, &FileMonitoring::FileChanged, this, &FileMonitoring::HandleFileChanged);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &FileMonitoring::CheckFileStatus);
    timer->start();
}

QString FileMonitoring::getFilePath() const {
    return filePath;
}

QFileInfo FileMonitoring::getFileName() const {
    return fileInfo.fileName();
}

QString FileMonitoring::getFileSize() const {
    qint64 size = fileInfo.size();
    QString unit;

    if (size >= 1024*1024*1024) {
        size /= 1024*1024*1024;
        unit = "GB";
    } else if (size >= 1024*1024) {
        size /= 1024*1024;
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
