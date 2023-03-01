#include "TaskMpi.h"

TaskMpi::TaskMpi(QObject *parent):QObject(parent){
    int argc=10;
    char **argv;
    qDebug()<<"init:"<<MPI_Init(&argc,&argv);
    qDebug()<<"rank:"<< MPI_Comm_rank(MPI_COMM_WORLD, &id_);
    qDebug()<<"size:"<<MPI_Comm_size(MPI_COMM_WORLD, &process_num_);
    qDebug()<<"id:"<<id_<<" size:"<<process_num_;   
   
}
TaskMpi::~TaskMpi(){
   MPI_Finalize();
}

void TaskMpi::run_task(){
   for (int source_id = 1; source_id < process_num_; source_id++) {
        char rcv_msg[100]={0};        
        MPI_Recv(rcv_msg, 100, MPI_CHAR, source_id, 99,MPI_COMM_WORLD, &mpi_status_);
        qDebug()<<QString("接收到第%1号进程发送的消息：%2").arg(source_id).arg(rcv_msg);
    }
}

void TaskMpi::sendMsg(){
    QString msg=QString("hello world:%1").arg(id_);
    MPI_Send(msg.toStdString().c_str(), msg.length(), MPI_CHAR, 0, 99,MPI_COMM_WORLD);
}

