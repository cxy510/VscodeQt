#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include "device.h"
#include "TableViewPrint.h"
#include "TaskTcpClient.h"
#include "ThreadManager.h"


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
    void intMoudle();
    void initConnect();
    
    Ui::MainWindow *ui; 
     
    ThreadManager thread_pool_; // 线程池 
    TaskTcpClient *task_tcp_client1_=NULL;
    TaskTcpClient *task_tcp_client2_=NULL;
    TableViewPrint *tableview_print_=NULL;// 表格
};
#endif // MAINWINDOW_H
