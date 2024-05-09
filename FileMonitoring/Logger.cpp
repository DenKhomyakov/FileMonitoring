#include "Logger.h"
#include "FileMonitoring.h"

void Logger::printInitialFileInfo(FileMonitoring* fileMonitoring) {
    qDebug() << "File name: " << fileMonitoring->getFileName();
    qDebug() << "File path: " << fileMonitoring->getFilePath();
    qDebug() << "File size: " << fileMonitoring->getFileSize();
    qDebug() << "Date and time of creation: " << fileMonitoring->getFileBirthTime();
    qDebug() << "";
}

void Logger::printFileExistsAndModified(FileMonitoring* fileMonitoring) {
    qDebug() << "File exists and has been modified";
    qDebug() << "File size: " << fileMonitoring->getFileSize();
    qDebug() << "";
}

void Logger::printFileExistsAndNotModified(FileMonitoring* fileMonitoring) {
    qDebug() << "File exists and has not been modified";
    qDebug() << "File size: " << fileMonitoring->getFileSize();
    qDebug() << "";
}

void Logger::printFileNotExists() {
    qDebug() << "The file does not exist";
    qDebug() << "";
}

void Logger::printFileReturned(FileMonitoring* fileMonitoring) {
    qDebug() << "File has been detected";
    qDebug() << "File size: " << fileMonitoring->getFileSize();
    qDebug() << "";
}
