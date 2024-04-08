#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QDebug>

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath, QObject *parent);

    ~FileMonitoring() {}

    QString getFilePath();
    QFileInfo getFileName() const;
    qint64 getFileSize() const;
    QDateTime getTimeChanging();
    QDateTime getBirthTimeOfFile();

    void CheckFileStatus();

public slots:
    void HandleFileChanged();

signals:
    void FileChanged();

private:
    QString filePath;
    QFileInfo fileInfo;
    QFileSystemWatcher *watcher;
    QTimer *timer;
};

#endif // FILEMONITORING_H
