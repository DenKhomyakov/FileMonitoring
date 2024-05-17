#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QObject>

class File;

class Logger : public QObject {
    Q_OBJECT

public:
    Logger() {}
    ~Logger() {}

public slots:
    void printInitialFileInfo(File* file);
    void printFileExistsAndModified(File* file);
    void printFileExistsAndNotModified(File* file);
    void printFileNotExists(const QString& path);
    void printFileReturned(File* file);
};

#endif // LOGGER_H
