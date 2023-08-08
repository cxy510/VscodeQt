#ifndef PUBLIC_FILE_H
#define PUBLIC_FILE_H
#include <QObject>
#include <QString>
#include "log4qt/logger.h"
#include "log4qt/propertyconfigurator.h"
// #include "log4qt/loggerrepository.h"
// #include "log4qt/logmanager.h"

extern Log4Qt::Logger*g_log4;
void initLog4(QString str_conf);

enum LogLevel{kDebug=1,kInfo,kWarn,kError};
extern void Log4Data(LogLevel level,QString &msg);
#endif