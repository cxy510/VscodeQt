#include "TaskTcpClient.h"

TaskTcpClient::TaskTcpClient(QString tcp_name,QObject *parent) :tcp_name_(tcp_name),QObject(parent)
{
    rcv_buf_=new int8_t[RCV_MAX];
    device_tcp_=new DeviceTCPClient();
    initConnect();
}

TaskTcpClient::~TaskTcpClient()
{
    delete []rcv_buf_;
    rcv_buf_=NULL;

    delete device_tcp_;
    device_tcp_=NULL;    
    qDebug()<<"delete Task";
}

void TaskTcpClient::startConnectTcp(QString str_ip,uint32_t int_port){
    device_tcp_->startDevice(str_ip,int_port);
}

void TaskTcpClient::run_task()
{       
    int32_t rcv_len=0;
    device_tcp_->rcvData(rcv_buf_,rcv_len);  

    if (rcv_len<=0) {
        this_thread::sleep_for(chrono::milliseconds(50));//sleep 1毫秒
    }else{
         qDebug()<< "线程id："<< QThread::currentThreadId()<<"收到数据 "<<QString::fromLocal8Bit((char*)rcv_buf_,rcv_len);
    }  
}

void TaskTcpClient::initConnect(){
    connect(device_tcp_->tcp_socket_, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(device_tcp_->tcp_socket_, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));   

}

void TaskTcpClient::slotConnected(){
      qDebug()<<"TCP连接成功 "<<tcp_name_;
}

void TaskTcpClient::slotDisconnected(){
      qDebug()<<"TCP断开链接 "<<tcp_name_;
}



// 发送
int TaskTcpClient::sendData(const char *buf,int buf_len){
    return device_tcp_->sendData(buf,buf_len);
}