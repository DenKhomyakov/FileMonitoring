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

// Передаю параметры в emit в FileMonitoring.cpp (то есть через сигналы), далее в Logger.h и Logger.cpp устраиваю приёмку этого сигнала и соответствующий вывод информации
// Продумать сигналы и слоты для следующих ситуаций:
/*
 1. Изначальная информация о файле (имя, путь, размер, дата создания)
 2. Файл сушествует и не изменён
 3. Файл существует и был изменён
 4. Файла не существует (удалён или изначально не было)
 5. Файл был возвращён (восстановлен после удаленния, либо только что создан)
*/
// После этого настроить сигнально-слотовое соеддинение (коннекты), причём сигналы в FileMonitoring.h, а слоты в Logger.h
