#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>

class File {
public:
    File(const QString& path);

    QString getFilePath() const;
    QString getFileName() const;
    QString getFileSize() const;
    QDateTime getTimeChanging() const;
    QDateTime getFileBirthTime() const;

    //void setInfo(const QFileInfo& info);
    void refreshFileInfo();
    const QFileInfo& getFileInfo();

    void setRemoved(bool flag);
    bool isRemoved();

    void setFileModifiedShown(bool flag);
    bool isFileModifiedShown();

    void setFileNotModifiedShown(bool flag);
    bool isFileNotModifiedShown();

    bool operator==(const File& other) const;

private:
    QString filePath;
    QFileInfo fileInfo;

    bool fileModifiedShown;
    bool fileNotModifiedShown;
    bool fileRemoved;
};

#endif // FILE_H
