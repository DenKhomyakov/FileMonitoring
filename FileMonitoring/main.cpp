#include <QCoreApplication>
#include "FileMonitoring.h"
#include <thread>
#include <QDebug>


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "RUS");

    qInfo() << "\tFile monitoring program" << "\n";

    FileMonitoring fileMonitor("D:/Test/f1.txt");

    return a.exec();
}
