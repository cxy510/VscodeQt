#ifndef __TASK_TCP_CLIENT_H__
#define __TASK_TCP_CLIENT_H__

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QThread>

class TaskTcpClient:: public QObject, public QRunnable
{
        Q_OBJECT
public:
    explicit TaskTcpClient(QObject *parent = nullptr);
    ~TaskTcpClient();
protected:
    void run();
}

#endif
