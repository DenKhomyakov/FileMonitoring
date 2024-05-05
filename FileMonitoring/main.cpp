#include <QCoreApplication>
#include "FileMonitoring.h"
#include <thread>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "RUS");

    FileMonitoring fileMonitor("D:/Test/f1.txt", nullptr);

    return a.exec();
}
