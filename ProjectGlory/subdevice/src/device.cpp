#include <iostream>

#include "device.h"

DeviceTCPClient::DeviceTCPClient(){
    if(tcp_socket_==NULL){
        tcp_socket_=new QTcpSocket;
    }
    initConnect();
}

DeviceTCPClient::~DeviceTCPClient(){
    
}

void DeviceTCPClient::initConnect(){

    // connect(tcp_socket_, &QTcpSocket::connected, this, &DeviceTCPClient::onConnected);
    // connect(tcp_socket_, &QTcpSocket::disconnected, this, &DeviceTCPClient::onDisconnected);
    // connect(tcp_socket_, &QTcpSocket::stateChanged, this, &DeviceTCPClient::onSocketStateChange);
    // connect(tcp_socket_, &QTcpSocket::readyRead, this, &DeviceTCPClient::onSocketReadyRead);
}

void DeviceTCPClient::startDevice(QString str_ip,uint32_t int_port){
     if(tcp_socket_==NULL){
        tcp_socket_=new QTcpSocket;
     }

    tcp_socket_->connectToHost(str_ip,int_port);
}

// 线程执行函数
void DeviceTCPClient::plus(){

    
}