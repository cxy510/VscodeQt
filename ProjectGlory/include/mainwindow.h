#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <QCloseEvent>
#include "device.h"

#include "TaskTcpClient.h"
#include "ThreadManager.h"
#include "AnalyzeSqlite.h"
#include "TableViewSql.h"


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
    void slotEndTcp();

    void slotOpenSqlite();
    void slotQuerySqlite();
    void slotTableDisplay();

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
    AnalyzeSqlite analyze_sqlite_;

    TableViewSQL *table_mgr_sql_=NULL;
    
    QSqlTableModel *model_test;
};
#endif // MAINWINDOW_H
