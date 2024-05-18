#include "File.h"
#include <QDateTime>

File::File(const QString& path) : filePath(path) {
    fileInfo = QFileInfo(path);

    fileModifiedShown = false;
    fileNotModifiedShown = false;
    fileRemoved = false;
}

QString File::getFilePath() const {
    return filePath;
}

QString File::getFileName() const {
    return fileInfo.fileName();
}

QString File::getFileSize() const {
    qint64 size = fileInfo.size();
    QString unit;

    if (size >= 1024 * 1024 * 1024) {
        size /= 1024 * 1024 * 1024;
        unit = "GB";
    } else if (size >= 1024 * 1024) {
        size /= 1024 * 1024;
        unit = "MB";
    } else if (size >= 1024) {
        size /= 1024;
        unit = "KB";
    } else {
        unit = "B";
    }

    return QString("%1 %2").arg(size).arg(unit);
}

QDateTime File::getTimeChanging() const {
    return fileInfo.lastModified();
}

QDateTime File::getFileBirthTime() const {
    return fileInfo.birthTime();
}

/*
void File::setInfo(const QFileInfo& info) {
    fileInfo = info;
}
*/

void File::refreshFileInfo() {
    return fileInfo.refresh();
}

const QFileInfo& File::getFileInfo() {
    return fileInfo;
}

void File::setRemoved(bool flag) {
    fileRemoved = flag;
}

bool File::isRemoved() {
    return fileRemoved;
}

void File::setFileModifiedShown(bool flag) {
    fileModifiedShown = flag;
}

bool File::isFileModifiedShown() {
    return fileModifiedShown;
}

void File::setFileNotModifiedShown(bool flag) {
    fileNotModifiedShown = flag;
}

bool File::isFileNotModifiedShown() {
    return fileNotModifiedShown;
}

bool File::operator==(const File& other) const {
    return filePath == other.filePath;
}
