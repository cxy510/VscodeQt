#include <iostream>

#include "device.h"

DeviceTCPClient* CreateDeviceTCPClient(){
    return new DeviceTCPClient;
}

DeviceTCPClient::DeviceTCPClient(){
    if(tcp_socket_==NULL){
        tcp_socket_=new QTcpSocket;
    }
    initConnect();
}

DeviceTCPClient::~DeviceTCPClient(){
    if(tcp_socket_!=NULL){
        tcp_socket_->close();
        delete tcp_socket_;
        tcp_socket_=NULL;
    }
}

void DeviceTCPClient::initConnect(){
}

void DeviceTCPClient::startDevice(QString str_ip,uint32_t int_port){
     if(tcp_socket_==NULL){
        tcp_socket_=new QTcpSocket;
     }

    tcp_socket_->connectToHost(str_ip,int_port);
}

// 线程执行函数
bool DeviceTCPClient::plus(){
    if(tcp_socket_&&tcp_socket_->canReadLine()) {   
        memset(rcv_buf,0,sizeof(rcv_buf));    
        rcv_len=0;          
        rcv_len=tcp_socket_->readLine((char*)rcv_buf,RCV_MAX);
        return true;
    }
    return false;
}

// 数据接收函数
 void DeviceTCPClient::rcvData(int8_t *buf,int32_t &buf_len,uint32_t read_size){    
    if(tcp_socket_!=NULL&&tcp_socket_->isOpen()) {  
        buf_len=tcp_socket_->readLine((char*)buf,read_size);
        // qDebug()<<tcp_socket_->localPort()<<" read num:"<<buf_len;
    }
 }

// 发送
int DeviceTCPClient::sendData(const char *buf,int buf_len){
    tcp_socket_->write(buf,buf_len);
}
