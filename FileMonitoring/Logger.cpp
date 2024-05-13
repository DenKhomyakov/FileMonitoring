#include "Logger.h"
#include "File.h"
#include <QDateTime>
#include <QDebug>

void Logger::printInitialFileInfo(File* file) {
    qDebug() << "File name: " << file->getFileName();
    qDebug() << "File path: " << file->getFilePath();
    qDebug() << "File size: " << file->getFileSize();
    qDebug() << "Date and time of creation: " << file->getFileBirthTime();
    qDebug() << "";
}

void Logger::printFileExistsAndModified(File* file) {
    qDebug() << "File " << file->getFileName() << " exists and has been modified";
    qDebug() << "File size: " << file->getFileSize();
    qDebug() << "";
}

void Logger::printFileExistsAndNotModified(File* file) {
    qDebug() << "File " << file->getFileName() << " exists and has not been modified";
    qDebug() << "File size: " << file->getFileSize();
    qDebug() << "";
}

void Logger::printFileNotExists(const QString& path) {
    qDebug() << "File on " << path << " does not exist";
    qDebug() << "";
}

void Logger::printFileReturned(File* file) {
    qDebug() << "File " << file->getFileName() << " has been detected";
    qDebug() << "File size: " << file->getFileSize();
    qDebug() << "";
}
