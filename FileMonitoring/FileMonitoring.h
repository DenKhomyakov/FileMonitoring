#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QFileInfo>
#include <QString>
#include <QDebug>

class FileMonitoring : public QFileInfo {

private:
    QString filePath;
    QFileInfo fileInfo;
};

#endif // FILEMONITORING_H
