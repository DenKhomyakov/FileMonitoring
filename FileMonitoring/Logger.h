#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDebug>

class Logger {
public:
    static void loggerInfo(const QString& message);
    static void loggerError(const QString& message);
};

#endif // LOGGER_H
