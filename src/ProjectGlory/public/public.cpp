#include "public.h"
#include <QApplication>

Log4Qt::Logger*g_log4=NULL;
void initLog4(QString str_conf){
    QString str_path=QString::fromLocal8Bit(qApp->applicationDirPath().toLocal8Bit())+"/"+str_conf;
    bool result=Log4Qt::PropertyConfigurator::configure(str_path);
    g_log4=Log4Qt::Logger::logger("GLORY");
    if (result) {
        QString str="***********Log4日志初始化成功*************";
        Log4Data(kInfo,str);
    }else{
        QString str="***********Log4日志初始化失败*************";
        Log4Data(kInfo,str);
    }
    

}

void Log4Data(LogLevel level,QString &msg){
    switch (level)
    {
    case kDebug:
        g_log4->debug(msg);
        break;
    case kInfo:
        g_log4->info(msg);
        break;
    case kWarn:
        g_log4->warn(msg);
        break;
    case kError:
        g_log4->error(msg);
        break;    
    default:
        break;
    }
}

