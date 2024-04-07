#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QFileInfo>
#include <QString>
#include <QDateTime>
#include <QDebug>

class FileMonitoring : public QFileInfo {
public:
    FileMonitoring(const QString& filePath);

    ~FileMonitoring() {}

    QString getFilePath();
    QFileInfo getFileName() const;
    qint64 getFileSize() const;
    QDateTime getTimeChanging();

private:
    QString filePath;
    QFileInfo fileInfo;
};

#endif // FILEMONITORING_H
