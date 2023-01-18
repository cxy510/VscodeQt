#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sublib1.h"
#include "device.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
 
    
private:
    void initDll();
    void initConnect();
    Ui::MainWindow *ui;
    DeviceTCPClient *device_tcp_client_;     
   

private slots:
    void slotLib1Clicked();
    void slotConnectTcp();
};
#endif // MAINWINDOW_H
