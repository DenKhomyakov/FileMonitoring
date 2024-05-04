#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QByteArray>
#include <QDebug>

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath, QObject *parent);

    ~FileMonitoring() {}

    QString getFilePath() const;
    QFileInfo getFileName() const;
    QString getFileSize() const;
    QDateTime getTimeChanging() const;
    QDateTime getFileBirthTime() const;

    void checkFileStatus();

public slots:
    void handleFileChanged();

signals:
    void fileChanged();

private:
    QString filePath;
    QFileInfo fileInfo;
    QFileSystemWatcher *watcher;
    QTimer *timer;
};

#endif // FILEMONITORING_H
