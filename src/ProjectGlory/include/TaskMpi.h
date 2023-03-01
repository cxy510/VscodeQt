#ifndef __TASK_MPI_H__
#define __TASK_MPI_H__

#include <QObject>
#include <QDebug>
#include <iostream>
#include "Thread.h"
#include "mpi/mpi.h"

using namespace std;

class TaskMpi:public QObject,public Runnable
{
        Q_OBJECT
public:
    explicit TaskMpi(QObject *parent = nullptr);
    ~TaskMpi();  
    void sendMsg();

protected:
    void run_task()override;

private:  
    int process_num_=0;// 进程数量
    int id_=1;// 进程id
    int source_id_=0; // 接收的进程号
    MPI_Status mpi_status_;// mpi状态信息
};

#endif
