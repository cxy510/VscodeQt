#include "TaskTcpClient.h"

TaskTcpClient::TaskTcpClient(QObject *parent) : QObject(parent)
{
}

TaskTcpClient::~TaskTcpClient()
{
    qDebug()<<"delete Task";
}

void TaskTcpClient::run()
{
    int i = 10;
    while(i--)
    {
        qDebug() << "线程id："<< QThread::currentThreadId()<< QString(":剩余%1").arg(i);
        QThread::sleep(1);
    }
}
