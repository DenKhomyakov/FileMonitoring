#include <QCoreApplication>
#include "FileMonitoring.h"
#include <thread>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "RUS");

    cout << "\tFile monitoring program" << "\n" << endl;

    FileMonitoring fileMonitor("D:/Test/f1.txt");

    return a.exec();
}
