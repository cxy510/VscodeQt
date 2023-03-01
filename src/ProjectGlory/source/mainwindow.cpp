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
    //intMoudle();
    initConnect();      

}
MyMainWindow::~MyMainWindow()
{
    delete ui;
    // if(task_tcp_client_){
    //     delete task_tcp_client_;task_tcp_client_=NULL;
    // }  
    if (table_mgr_sql_) {
        delete table_mgr_sql_;
        table_mgr_sql_=NULL;
    }
      
}

void MyMainWindow::initConnect(){

    // TCP Client
    connect(ui->btn_conect,SIGNAL(clicked()),this,SLOT(slotConnectTcp()));
    connect(ui->btn_send_tcp,SIGNAL(clicked()),this,SLOT(slotSendTcp()));
    connect(ui->btn_end_tcp,SIGNAL(clicked()),this,SLOT(slotEndTcp()));

    // Analzye db
    connect(ui->btn_opensqlite,SIGNAL(clicked()),this,SLOT(slotOpenSqlite()));
    connect(ui->btn_query,SIGNAL(clicked()),this,SLOT(slotQuerySqlite()));
    connect(ui->btn_sql_model,SIGNAL(clicked()),this,SLOT(slotTableDisplay()));
    
    // Mpi
    connect(ui->btn_init_mpi,SIGNAL(clicked()),this,SLOT(slotConnectMpi()));
    connect(ui->btn_send_mpi,SIGNAL(clicked()),this,SLOT(slotSendMpi()));
    connect(ui->btn_end_mpi,SIGNAL(clicked()),this,SLOT(slotEndMpi()));
}

void MyMainWindow::intMoudle(){
    //device_tcp_client_=new DeviceTCPClient;//CreateDeviceTCPClient();
    task_tcp_client1_=new TaskTcpClient("task1");
    thread_pool_.pushtask(task_tcp_client1_);
    task_tcp_client2_=new TaskTcpClient("task2");
    thread_pool_.pushtask(task_tcp_client2_);
    thread_pool_.startThread();    
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

void MyMainWindow::initUi(){
}


void MyMainWindow::closeEvent(QCloseEvent *event){
     thread_pool_.endThread();
}

void MyMainWindow::slotEndTcp(){
    thread_pool_.endThread();
}

void MyMainWindow::slotOpenSqlite(){
    QString path=ui->lineEdit_str->text();
    analyze_sqlite_.openSqlite("wym_text1",path);
    table_mgr_sql_=new TableViewSQL(ui->tableView,analyze_sqlite_.getDatabase());
}

void MyMainWindow::slotQuerySqlite(){
     QString query_str=ui->lineEdit_query->text();
     shared_ptr<QSqlQuery> result=analyze_sqlite_.querySqlite(query_str);
     qDebug()<<"query_rows:"<<analyze_sqlite_.getQueryRow(result);
}

void MyMainWindow::slotTableDisplay(){
    table_mgr_sql_->selectTable("secnum",QString("tlj = '%1'").arg("01H"));   
}

void MyMainWindow::slotConnectMpi(){
    task_mpi_=new TaskMpi();
    thread_pool_.pushtask(task_mpi_);
    thread_pool_.startThread();    
}

void MyMainWindow::slotSendMpi(){
    task_mpi_->sendMsg();
}

void MyMainWindow::slotEndMpi(){
    thread_pool_.endThread();
}
