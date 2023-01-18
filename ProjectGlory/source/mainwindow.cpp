#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QIcon>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    setWindowIcon(QIcon(":/resource/resources/ico.jpg"));    
    initConnect();    
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
    delete device_tcp_client_;device_tcp_client_=NULL;
}

void MyMainWindow::initConnect(){
    connect(ui->btn_lib1,SIGNAL(clicked()),this,SLOT(slotLib1Clicked()));
    connect(ui->btn_conect,SIGNAL(clicked()),this,SLOT(slotConnectTcp()));
}

void MyMainWindow::initDll(){
    device_tcp_client_=new DeviceTCPClient;
}

void MyMainWindow::slotLib1Clicked(){
     sublib1 hi;
     hi.print();
    
    //device_tcp_client_
     // IDevice id1;
     // id1.print();
}

void MyMainWindow::slotConnectTcp(){
    device_tcp_client_->startDevice("127.0.0.1",9999);
    
}