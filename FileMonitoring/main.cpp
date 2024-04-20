#include <QCoreApplication>
#include "FileMonitoring.h"
#include <thread>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setlocale(LC_ALL, "RUS");

    FileMonitoring fileMonitor("D:/Test/f1.txt", nullptr);

    while (true) {
        fileMonitor.CheckFileStatus();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
