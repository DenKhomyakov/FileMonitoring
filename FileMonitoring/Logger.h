#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDebug>
#include <QObject>

class FileMonitoring;

class Logger : public QObject {
    Q_OBJECT

public:
    Logger() {}
    ~Logger() {}

public slots:
    void printInitialFileInfo(FileMonitoring* fileMonitoring);
    void printFileExistsAndModified(FileMonitoring* fileMonitoring);
    void printFileExistsAndNotModified(FileMonitoring* fileMonitoring);
    void printFileNotExists();
    void printFileReturned(FileMonitoring* fileMonitoring);
};

#endif // LOGGER_H
