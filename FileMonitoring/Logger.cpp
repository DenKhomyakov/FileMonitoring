#include "Logger.h"
#include "File.h"
#include <QDateTime>
#include <QDebug>

void Logger::printInitialFileInfo(File* file) {
    qInfo() << "File name: " << file->getFileName();
    qInfo() << "File path: " << file->getFilePath();
    qInfo() << "File size: " << file->getFileSize();
    qInfo() << "Date and time of creation: " << file->getFileBirthTime();
    qInfo() << "";
}

void Logger::printFileExistsAndModified(File* file) {
    qInfo() << "File " << file->getFileName() << " exists and has been modified";
    qInfo() << "File size: " << file->getFileSize();
    qInfo() << "";
}

void Logger::printFileExistsAndNotModified(File* file) {
    qInfo() << "File " << file->getFileName() << " exists and has not been modified";
    qInfo() << "File size: " << file->getFileSize();
    qInfo() << "";
}

void Logger::printFileNotExists(const QString& path) {
    qInfo() << "File on " << path << " does not exist";
    qInfo() << "";
}

void Logger::printFileReturned(File* file) {
    qInfo() << "File " << file->getFileName() << " has been detected";
    qInfo() << "File size: " << file->getFileSize();
    qInfo() << "";
}
