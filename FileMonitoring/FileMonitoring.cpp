#include "FileMonitoring.h"
#include <QDateTime>

FileMonitoring::FileMonitoring(const QString& filePath) : QFileInfo(filePath) {
    this->filePath = filePath;
    fileInfo = QFileInfo(filePath);
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
