#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <QCloseEvent>
#include "device.h"

#include "TaskTcpClient.h"
#include "TaskMpi.h"
#include "ThreadManager.h"
#include "AnalyzeSqlite.h"

#include "tableview/TableViewSql.h"
#include "PublicType.pb.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
 
public slots:
    void slotConnectTcp();
    void slotSendTcp();

    void slotOpenSqlite();
    void slotQuerySqlite();
    void slotTableDisplay();
    void slotEncryptSqlite();
    void slotDecryptSqlite();

    void slotInitBlockMpi();
    void slotInitNoBlockMpi();
    void slotSendBlockMpi();
    void slotSendNoBlockMpi();

    void slotBeginThreadPool();
    void slotEndThreadPool();

    void slotCompress();// 压缩文件夹
    void slotUnCompress();// 解压压缩包
    void slotCompressData();// 压缩数据流
    void slotUnCompressData();// 解压缩数据流

    void slotCompressFile();// 逐个文件压缩
    void slotUnCompressFile();// 逐个文件解压

protected:
    void closeEvent(QCloseEvent *event);
    
private:
    void initUi();
    void intMoudle();
    void initConnect();    

    Ui::MainWindow *ui; 
     
    ThreadManager thread_pool_; // 线程池 
    TaskTcpClient *task_tcp_client1_=NULL;
    TaskTcpClient *task_tcp_client2_=NULL;
    TaskMpi*task_mpi_=NULL;// 
    AnalyzeSqlite analyze_sqlite_;
    TableViewSQL *table_mgr_sql_=NULL;  

    QString temp_compress_file_ = "TempCompressFile";
  
};
#endif // MAINWINDOW_H
