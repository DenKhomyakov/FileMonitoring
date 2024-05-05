#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QDebug>

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath, QObject *parent);

    ~FileMonitoring() {}

    QString getFilePath() const;
    QString getFileName() const;
    QString getFileSize() const;
    QDateTime getTimeChanging() const;
    QDateTime getFileBirthTime() const;

public slots:
    void checkFileStatus();

signals:
    void fileReturned();
    void fileChanged();
    void fileNotChanged();

private:
    QString filePath;
    QFileInfo fileInfo;
    QTimer *timer;

    bool firstInfoMessageShown;
    bool fileChangedShown;
    bool fileNotChangedShown;

    bool fileRemoved;
};

#endif // FILEMONITORING_H
