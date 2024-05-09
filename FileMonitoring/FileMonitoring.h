#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QTimer>

class Logger;

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath);

    ~FileMonitoring();

    QString getFilePath() const;
    QString getFileName() const;
    QString getFileSize() const;
    QDateTime getTimeChanging() const;
    QDateTime getFileBirthTime() const;

public slots:
    void checkFileStatus();

signals:
    void initialFileInfo(FileMonitoring*);
    void fileExistsAndModified(FileMonitoring*);
    void fileExistsAndNotModified(FileMonitoring*);
    void fileNotExists();
    void fileReturned(FileMonitoring*);

private:
    QString filePath;
    QFileInfo fileInfo;
    QTimer *timer;

    bool initialFileInfoShown;
    bool fileModifiedShown;
    bool fileNotModifiedShown;
    bool fileRemoved;

    Logger* logger;
};

#endif // FILEMONITORING_H
