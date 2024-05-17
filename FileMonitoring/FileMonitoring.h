#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QList>
#include "File.h"

class Logger;

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring();
    ~FileMonitoring();

    void addFile(const QString& path);

    void removeFile(const QString& path);
    void removeFile(const File& file);

public slots:
    void checkFileStatus();

signals:
    void initialFileInfo(File*);
    void fileExistsAndModified(File*);
    void fileExistsAndNotModified(File*);
    void fileNotExists(const QString& path);
    void fileReturned(File*);

private:
    QList<File> repository;
    QTimer *timer;
    Logger* logger;
};

#endif // FILEMONITORING_H
