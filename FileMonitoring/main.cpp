#include <QCoreApplication>
#include "FileMonitoring.h"
#include <thread>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "RUS");

    qInfo() << "\tFile monitoring program" << "\n";

    FileMonitoring fileMonitoring1;
    fileMonitoring1.addFile("../f1.txt");

    FileMonitoring fileMonitoring2;
    fileMonitoring2.addFile("../f2.txt");

    return a.exec();
}
