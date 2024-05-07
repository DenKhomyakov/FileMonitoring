#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QTimer>

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath);

    ~FileMonitoring() {}

    QString getFilePath() const;
    QString getFileName() const;
    QString getFileSize() const;
    QDateTime getTimeChanging() const;
    QDateTime getFileBirthTime() const;

    void emitInitialFileInfo();
    void emitFileNotExists();

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

    bool firstInfoMessageShown;
    bool fileChangedShown;
    bool fileNotChangedShown;

    bool fileRemoved;
};

#endif // FILEMONITORING_H
