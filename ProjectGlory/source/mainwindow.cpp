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
    initDll();
    initConnect();    
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
    delete device_tcp_client_;device_tcp_client_=NULL;
}

void MyMainWindow::initConnect(){
    connect(ui->btn_lib1,SIGNAL(clicked()),this,SLOT(slotLib1Clicked()));

    // TCP Client
    connect(ui->btn_conect,SIGNAL(clicked()),this,SLOT(slotConnectTcp()));
    connect(ui->btn_send_tcp,SIGNAL(clicked()),this,SLOT(slotSendTcp()));
    
    //device_tcp_client_->tcp_socket_;
   connect(device_tcp_client_->tcp_socket_, SIGNAL(connected()), this, SLOT(slotConnected()));
    //connect(device_tcp_client_->tcp_socket_, &QTcpSocket::connected, this, &MyMainWindow::slotConnected);    
}

void MyMainWindow::initDll(){
    device_tcp_client_=new DeviceTCPClient;//CreateDeviceTCPClient();
}

void MyMainWindow::slotLib1Clicked(){
    //printMsg("中文");
    device_tcp_client_->plus();
}

void MyMainWindow::slotConnectTcp(){
    device_tcp_client_->startDevice("127.0.0.1",9999);

}

void MyMainWindow::slotSendTcp(){
    QString str="hello";
    device_tcp_client_->sendData(str.toStdString().c_str(),str.length());
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