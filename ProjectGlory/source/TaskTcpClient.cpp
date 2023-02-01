#include "TaskTcpClient.h"

TaskTcpClient::TaskTcpClient(QObject *parent) : QObject(parent)
{
    rcv_buf_=new int8_t[RCV_MAX];
}

TaskTcpClient::~TaskTcpClient()
{
    delete []rcv_buf_;
    rcv_buf_=NULL;
    qDebug()<<"delete Task";
}

void TaskTcpClient::startConnectTcp(QString str_ip,uint32_t int_port){
    device_tcp_.startDevice(str_ip,int_port);
}

void TaskTcpClient::run()
{
   // while(1)
   {        
         int32_t rcv_len=0;
         device_tcp_.rcvData(rcv_buf_,rcv_len);
         qDebug()<< "线程id："<< QThread::currentThreadId()<<"收到数据 "<<QString::fromLocal8Bit((char*)rcv_buf_,rcv_len);
        
        this_thread::sleep_for(chrono::milliseconds(500));//sleep 1毫秒
    }
   
    // int i = 10;
    // while(i--)
    // {
    //     qDebug() << "线程id："<< QThread::currentThreadId()<< QString(":剩余%1").arg(i);
    //     QThread::sleep(1);
    // }
}

void TaskTcpClient::initConnect(){
    connect(device_tcp_.tcp_socket_, SIGNAL(connected()), this, SLOT(slotConnected()));
}

void TaskTcpClient::slotConnected(){
      qDebug()<<"TCP连接成功";
}

// 发送
int TaskTcpClient::sendData(const char *buf,int buf_len){
    return device_tcp_.sendData(buf,buf_len);
}