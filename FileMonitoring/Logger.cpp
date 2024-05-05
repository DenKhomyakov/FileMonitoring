#include "Logger.h"

void Logger::loggerInfo(const QString& message) {
    qDebug() << "INFO: " << message;
}

void Logger::loggerError(const QString& message) {
    qDebug() << "ERROR: " << message;
}
