#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sublib1.h"
#include "device.h"
#include "TableViewPrint.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
    void printMsg(QString str);
 
public slots:
    void slotLib1Clicked();
    void slotConnectTcp();
    void slotSendTcp();
    void slotConnected();
    
private:
    void initUi();
    void initDll();
    void initConnect();
    Ui::MainWindow *ui;
    DeviceTCPClient *device_tcp_client_;     
    TableViewPrint *tableview_print_=NULL;
};
#endif // MAINWINDOW_H
