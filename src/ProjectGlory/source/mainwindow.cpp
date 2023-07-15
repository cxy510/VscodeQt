#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMetaProperty>
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
    initPrintMetaProperty();
    initTestCode();
    initQss();
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

void MyMainWindow::initQss(){
    ui->lineEdit_dynamic->setProperty("dynamic_background",true);
    QString qss_path=QString::fromLocal8Bit(qApp->applicationDirPath().toLocal8Bit())+"/glory.qss";
    qDebug()<<"qss_path:"<<qss_path;
    QFile file_qss(qss_path);
    qDebug()<<"qss_file_open:"<<file_qss.open(QFile::ReadOnly);
    if (file_qss.isOpen()) {
        qApp->setStyleSheet(file_qss.readAll());
        file_qss.close();
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
    connect(ui->btn_encrypt,SIGNAL(clicked()),this,SLOT(slotEncryptSqlite()));
    connect(ui->btn_decrypt,SIGNAL(clicked()),this,SLOT(slotDecryptSqlite()));
    
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
    connect(ui->btn_uncompress,SIGNAL(clicked()),this,SLOT(slotUnCompress()));    
    connect(ui->btn_compress_data,SIGNAL(clicked()),this,SLOT(slotCompressData()));
    connect(ui->btn_uncompress_data,SIGNAL(clicked()),this,SLOT(slotUnCompressData()));    
    connect(ui->btn_compress_file_list,SIGNAL(clicked()),this,SLOT(slotCompressFile()));
    connect(ui->btn_uncompress_file_list,SIGNAL(clicked()),this,SLOT(slotUnCompressFile()));    

    // 模拟发送信号
    connect(ui->btn_send_signal,SIGNAL(clicked()),this,SLOT(slotSignalBtnClicked())); 
    connect(this,SIGNAL(signalRefresh()),this,SLOT(slotTimeOut())); 
    connect(ui->btn_test,SIGNAL(clicked()),this,SLOT(slotTestBtnClicked())); 
    
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

void MyMainWindow::slotEncryptSqlite(){
    QString path=ui->lineEdit_str->text();
    analyze_sqlite_.encryptSqlite(path);
}

void MyMainWindow::slotDecryptSqlite(){
    QString path=ui->lineEdit_str->text();
    analyze_sqlite_.decryptSqlite(path);
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
    zip_tool.compressDir(target_path+".zip",target_path);
}

void MyMainWindow::slotUnCompress(){
    ZipTool zip_tool;
    QString zip_path=ui->lineEdit__uncompress->text();

    QFileInfo info(zip_path);
    qDebug()<<"uncompress dir:"<<info.path();
    zip_tool.unCompressDir(zip_path,info.path());
}

// 压缩数据流
void MyMainWindow::slotCompressData(){
    ZipTool zip_tool;
    QString file_path=ui->lineEdit_compress_data->text();    
    
    quint64 totalBytes;
    QFile file(file_path);
    QByteArray read_byte;
    QByteArray OutByte;
    int *errorCode = NULL;
    if(!file.open(QFile::ReadOnly))
    {
        qDebug() << QString("Send file error! Cannot read XmlFile %1(%2).").arg(file_path).arg(file.errorString());
        return;
    }
 
    QDataStream out(&read_byte, QIODevice::WriteOnly);
    totalBytes = file.size();
    out.device()->seek(0);
    out<<file.readAll();
    file.close();
    read_byte.remove(0,4);
    qDebug()<<"totalBytes = "<<totalBytes;
    //qDebug()<<"SendByte = "<<read_byte.toHex();
 
    long outlength = zip_tool.compressData(OutByte,read_byte,errorCode);
    if(outlength != (-1))
    {
        //qDebug()<<"OutByte = "<<OutByte.toHex();
        qDebug()<<"outlength = "<<outlength;
 
    }

    QString compressed_file_path=qApp->applicationDirPath()+"/"+temp_compress_file_;
    QFile file_in(compressed_file_path);
    if(!file_in.open(QFile::WriteOnly))
    {
        qDebug() << QString("write file error! error code: %1.").arg(file_in.errorString());
        return;
    }
    file_in.resize(0);//清空原有图片内容
    file_in.write(OutByte.data(),OutByte.size());
    file_in.close();

}

// 解压缩数据流
void MyMainWindow::slotUnCompressData(){
    ZipTool zip_tool;
    quint64 totalBytes;
    QString compressed_file_path=qApp->applicationDirPath()+"/"+temp_compress_file_;
    QFile file(compressed_file_path);
    QByteArray read_bytes;
    QByteArray out_bytes;
    int *error_code = NULL;
    if(!file.open(QFile::ReadOnly))
    {
        qDebug() << QString("Send file error! Cannot read XmlFile %1(%2).").arg(compressed_file_path).arg(file.errorString());
        return;
    }
    QDataStream out(&read_bytes, QIODevice::WriteOnly);
    totalBytes = file.size();
    out.device()->seek(0);
    out<<file.readAll();
    file.close();  
    read_bytes.remove(0,4);
    qDebug()<<"uncompress totalBytes = "<<totalBytes;
    // qDebug()<<"uncompress SendByte = "<<read_bytes.toHex();


    long decodelenth = zip_tool.uncompressData(out_bytes,read_bytes,error_code);
    qDebug() << QString("uncompress size: %1,code：%2").arg(out_bytes.size()).arg(decodelenth);
    QFile file_out("uncompressFile");
    if(!file_out.open(QFile::WriteOnly))
    {
        qDebug() << QString("Send file error! Cannot write uncompressFile (%1).").arg(file_out.errorString());
        return;
    }
    file_out.resize(0);//清空原有图片内容
    file_out.write(out_bytes.data(),out_bytes.size());
    file_out.close();
}

// 逐个文件压缩
void MyMainWindow::slotCompressFile(){
    QString zip_name=QFileDialog::getSaveFileName(this,"压缩后文件名称","C:/Users/13523/Desktop",tr("*.zip"));
    if(zip_name.isEmpty())return;
    qDebug()<<"begin to compress";
    //QString target_path=qApp->applicationDirPath()+"/"+temp_compress_file_;
    ZipTool zip_tool;
    QString strPath = ui->lineEdit_file_list->text();
    QDir dir(strPath);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QFileInfo fileInfo, list)  {
        qDebug()<<"compress filepath:"<<fileInfo.filePath()<<"  filename:"<<fileInfo.fileName()<<"   target:"<<zip_name;
        zip_tool.compressSignalFile(fileInfo.fileName(),fileInfo.filePath(),zip_name);
    }
}

// 逐个文件解压
void MyMainWindow::slotUnCompressFile(){
    QString zip_name=QFileDialog::getOpenFileName(this,"压缩后文件名称","C:/Users/13523/Desktop",tr("*.zip"));
    if(zip_name.isEmpty())return;
    ZipTool zip_tool;
    QFileInfo file_info(zip_name);
    zip_tool.uncompressSignalFile(zip_name,file_info.path());
}

// 打印属性
void MyMainWindow::initPrintMetaProperty(){
    QObject *object = this;
    const QMetaObject *metaobject = object->metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i) {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant value = object->property(name);
        qDebug()<<QString::fromStdString(name)<<"-"<<value.toString();
    }

}

int num=0;
int &getIntNum(){
    return num;
}

void MyMainWindow::initTestCode(){
    int & num1=getIntNum();
    num1=2;
    qDebug()<<"num1:"<<num1<< "   num:"<<num;

    auto num2=getIntNum();
    num2=5;
    qDebug()<<"num2:"<<num2<< "   num:"<<num;

    // QToolButton
    // QToolButton *pButton=ui->toolButton;
    // pButton->setArrowType(Qt::LeftArrow);
    // pButton->setText("Left Arrow");
    // // 文本位于图标之下
    // pButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // pButton->setStyleSheet("QToolButton{border: none; background: rgb(68, 69, 73); color: rgb(0, 160, 230);}");


    // QAction *pAction = new QAction(this);
    // pAction->setText(QString::fromLocal8Bit("想定编辑"));
    // pAction->setIcon(QIcon(":/Images/logo"));
    // pButton->setIconSize(QSize(48, 48));
    // pAction->setToolTip(QString::fromLocal8Bit("三生三世"));
    // pButton->setDefaultAction(pAction);
    // pButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

}

void MyMainWindow::threadSendSignal(){
    for (int i =1; i < 6; i++)
    {
        qDebug()<<"!!!Send signal begin:"<<i;
        emit signalRefresh();
        qDebug()<<"!!!Send signal end:"<<i;
    }     
}

void MyMainWindow::slotSignalBtnClicked(){
    std::thread thread_send_signal(&MyMainWindow::threadSendSignal,this);
    thread_send_signal.detach();
}

void MyMainWindow::slotTimeOut(){
    static int loop=1;
    qDebug() << "===SlotTimeOut begin:"<<loop;
    QObject::sender()->blockSignals(true);
    QThread::sleep(2);
    QObject::sender()->blockSignals(false);
    qDebug() << "===SlotTimeOut end:"<<loop;
    loop++;
}

// 点击测试按钮事件
 void MyMainWindow::slotTestBtnClicked(){

    
 }