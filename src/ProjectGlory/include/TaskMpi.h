#ifndef __TASK_MPI_H__
#define __TASK_MPI_H__

#include <QObject>
#include <QDebug>
#include <iostream>
#include "Thread.h"


using namespace std;

class TaskMpi:public QObject,public Runnable
{
        Q_OBJECT
public:
    explicit TaskMpi(QObject *parent = nullptr);
    ~TaskMpi();  

protected:
    void run_task()override;

private:
   void initConnect();

};

#endif
