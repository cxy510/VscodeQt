#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QIcon>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    setWindowIcon(QIcon(":/resource/resources/ico.jpg"));    
    initUi();
    intMoudle();
    initConnect();    
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
    // if(task_tcp_client_){
    //     delete task_tcp_client_;task_tcp_client_=NULL;
    // }    
}

void MyMainWindow::initConnect(){
    connect(ui->btn_lib1,SIGNAL(clicked()),this,SLOT(slotLib1Clicked()));
    // TCP Client
    connect(ui->btn_conect,SIGNAL(clicked()),this,SLOT(slotConnectTcp()));
    connect(ui->btn_send_tcp,SIGNAL(clicked()),this,SLOT(slotSendTcp()));
    
  
}

void MyMainWindow::intMoudle(){
    //device_tcp_client_=new DeviceTCPClient;//CreateDeviceTCPClient();
    task_tcp_client1_=new TaskTcpClient;
    thread_pool_.pushtask(task_tcp_client1_);
    task_tcp_client2_=new TaskTcpClient;
    thread_pool_.pushtask(task_tcp_client2_);

    thread_pool_.startThread();
}

void MyMainWindow::slotLib1Clicked(){
    //printMsg("中文");
    //device_tcp_client_->plus();
}

void MyMainWindow::slotConnectTcp(){
    task_tcp_client1_->startConnectTcp("127.0.0.1",9999);
    task_tcp_client2_->startConnectTcp("127.0.0.1",9999);

}

void MyMainWindow::slotSendTcp(){
    QString str1="task1:hello";
    task_tcp_client1_->sendData(str1.toStdString().c_str(),str1.length());
    QString str2="task2:hello";
    task_tcp_client2_->sendData(str2.toStdString().c_str(),str2.length());
}

void MyMainWindow::slotConnected(){
     printMsg("TCP连接成功");
}

void MyMainWindow::initUi(){
   // tableview_print_=new TableViewPrint(ui->tableView_print);
}

void MyMainWindow::printMsg(QString str){
    ui->textEdit_print->append(str);
    // QStringList str_print;
    // str_print<<str;
    // tableview_print_->insertData(str_print);
}

void MyMainWindow::closeEvent(QCloseEvent *event){
     thread_pool_.endThread();
}