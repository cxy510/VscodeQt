#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QIcon>
#include "ziptool.h"

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

    // Analzye db
    connect(ui->btn_opensqlite,SIGNAL(clicked()),this,SLOT(slotOpenSqlite()));
    connect(ui->btn_query,SIGNAL(clicked()),this,SLOT(slotQuerySqlite()));
    connect(ui->btn_sql_model,SIGNAL(clicked()),this,SLOT(slotTableDisplay()));
    
    // Mpi
    connect(ui->btn_init_mpi_block,SIGNAL(clicked()),this,SLOT(slotInitBlockMpi()));
    connect(ui->btn_init_mpi_noblock,SIGNAL(clicked()),this,SLOT(slotInitNoBlockMpi()));
    connect(ui->btn_send_mpi,SIGNAL(clicked()),this,SLOT(slotSendBlockMpi()));
    connect(ui->btn_send_mpi_noblock,SIGNAL(clicked()),this,SLOT(slotSendNoBlockMpi()));

    // Begin ThreadPool
    connect(ui->btn_begin_threadpool,SIGNAL(clicked()),this,SLOT(slotBeginThreadPool()));
    connect(ui->btn_end_threadpool,SIGNAL(clicked()),this,SLOT(slotEndThreadPool()));

    // compress
    connect(ui->btn_compress,SIGNAL(clicked()),this,SLOT(slotCompress()));
    
}


void MyMainWindow::intMoudle(){
    //device_tcp_client_=new DeviceTCPClient;//CreateDeviceTCPClient();
  
}

void MyMainWindow::initUi(){

}

/***线程池***/
void MyMainWindow::slotBeginThreadPool(){
    thread_pool_.startThread();   
}

void MyMainWindow::slotEndThreadPool(){
    thread_pool_.endThread();  
}

// 增加结束线程池
void MyMainWindow::closeEvent(QCloseEvent *event){
    
}

/***TCP***/
void MyMainWindow::slotConnectTcp(){
    task_tcp_client1_=new TaskTcpClient("task1");
    thread_pool_.pushtask(task_tcp_client1_);
    task_tcp_client2_=new TaskTcpClient("task2");
    thread_pool_.pushtask(task_tcp_client2_);    
    task_tcp_client1_->startConnectTcp("127.0.0.1",9999);
    task_tcp_client2_->startConnectTcp("127.0.0.1",9999);
}

void MyMainWindow::slotSendTcp(){
    QString str1;
    GLORY::DataStruct ds_message;
    ds_message.set_num(1);
    ds_message.set_name("task1:hello");
    ds_message.set_type(GLORY::DataStruct::kType2);
    char snd_buf[1024];
    memset(snd_buf,0,sizeof(snd_buf));
    ds_message.SerializeToArray(snd_buf,ds_message.ByteSizeLong());
    task_tcp_client1_->sendData(snd_buf,ds_message.ByteSizeLong());

    QString str2="task2:hello";
    task_tcp_client2_->sendData(str2.toStdString().c_str(),str2.length());
}



/***SQLITE***/
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


/***MPI***/
void MyMainWindow::slotInitBlockMpi(){
    task_mpi_=new TaskMpi(TaskMpi::kIsBlock);
    if (task_mpi_->getProcessId()==0)// 0号进程才进行线程循环接收
    {
         thread_pool_.pushtask(task_mpi_);   
    }
    
   
    ui->lbl_mpi->setText(QString("Block进程号:%1").arg(task_mpi_->getProcessId()));
}

void MyMainWindow::slotInitNoBlockMpi(){
    task_mpi_=new TaskMpi(TaskMpi::kNotBlcok);
    if (task_mpi_->getProcessId()==0)// 0号进程才进行线程循环接收
    {
         thread_pool_.pushtask(task_mpi_);   
    }   
   
    ui->lbl_mpi->setText(QString("NoBlock进程号:%1").arg(task_mpi_->getProcessId()));
}

void MyMainWindow::slotSendBlockMpi(){
    task_mpi_->sendMsgBlock();
}

void MyMainWindow::slotSendNoBlockMpi(){
    task_mpi_->sendMsgNotBlock();
}


void MyMainWindow::slotCompress(){
    ZipTool zip_tool;
    QString target_path=ui->lineEdit_compress->text();
    zip_tool.compress(target_path+".zip",target_path);
}