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
#include <QtNetwork/QTcpSocket>

class IDevice
{
public:
    IDevice(){}
    virtual ~IDevice(){}
    virtual void plus()=0; // 线程执行函数
    QTcpSocket *socket=NULL;
   // QWidget *widget=NULL;

};

#endif
