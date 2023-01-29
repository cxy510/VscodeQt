/**
 *  @file      IDevice.h
 *  @brief     通信设备模块
 *  @author    cxy(wuyuming510@139.com)
 *  @date      2023-1-16
 *  @copyright 
 */

#ifndef __SUB_DEVICE_H__
#define __SUB_DEVICE_H__
//#include <QtNetwork>
#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>

#define SEND_MAX 20*1024
#define RCV_MAX  2*1024*1024

class IDevice
{
public:
    IDevice(){}
    virtual ~IDevice(){}
    virtual bool plus()=0; // 线程执行函数

};

class DeviceTCPClient:public IDevice
{
    //Q_OBJECT dll中无法添加该宏定义
    public:
        DeviceTCPClient();
        ~DeviceTCPClient();     
        void startDevice(QString str_ip,uint32_t int_port);
        QString getLocalIP();
        bool plus()override; // 线程执行函数
        int sendData(const char *buf,int buf_len);        
        QTcpSocket * tcp_socket_ = nullptr;  //socket

    private slots:
        //自定义槽函数
        void  onConnected() ;
        void  onDisconnected() ;
        void  onSocketStateChange(QAbstractSocket::SocketState socketState) ;
        void  onSocketReadyRead() ; //读取socket传入的数据

    private:
        void initConnect();        
        void rcvData(int8_t *buf,int32_t &buf_len,uint32_t read_size=RCV_MAX);
        bool misConnectService = false; //判断是否连接了服务器
        uint32_t rcv_len=0;
        uint8_t  rcv_buf[RCV_MAX];
};

//DllExport DeviceTCPClient* CreateDeviceTCPClient();



#endif
