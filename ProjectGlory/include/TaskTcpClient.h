#ifndef __TASK_TCP_CLIENT_H__
#define __TASK_TCP_CLIENT_H__

#include <QObject>
#include <QDebug>
#include <QThread>
#include <iostream>
#include <thread>
#include <chrono>
#include "device.h"
#include "Thread.h"

using namespace std;

class TaskTcpClient:public QObject,public Runnable
{
        Q_OBJECT
public:
    explicit TaskTcpClient(QObject *parent = nullptr);
    ~TaskTcpClient();
    void startConnectTcp(QString str_ip,uint32_t int_port);
    int sendData(const char *buf,int buf_len); 

public slots:
    void slotConnected();

protected:
    void run_task();

private:
   void initConnect();
   DeviceTCPClient device_tcp_;  
   int8_t  *rcv_buf_;

};

#endif
