#include "TaskMpi.h"

TaskMpi::TaskMpi(QObject *parent):QObject(parent){
    int argc=10;
    char **argv;
    cout<<"Begin init"<< std::endl; 
    MPI_Init(&argc,&argv);    
    MPI_Comm_rank(MPI_COMM_WORLD, &id_);  
    MPI_Comm_size(MPI_COMM_WORLD, &process_num_); 
    cout<<"id:"<<id_<<" size:"<<process_num_<< std::endl;      
}
TaskMpi::~TaskMpi(){
    cout<<"End Mpi id:"<<id_<<" size:"<<process_num_<< std::endl;   
    MPI_Finalize();
}

void TaskMpi::run_task(){
   for (int source_id = 1; source_id < process_num_; source_id++) {
        char rcv_msg[100]={0};     
       // cout<<"begin to rcv:"<<source_id<< " local pid:"<<id_<<endl;   
       //int len=MPI_Recv(rcv_msg, 100, MPI_CHAR, source_id, 99,MPI_COMM_WORLD, &mpi_status_); // 阻塞接收
        int len=MPI_Irecv(rcv_msg, 100, MPI_CHAR, source_id, 99,MPI_COMM_WORLD, &request_);// 非阻塞接收
       
        
        cout<<"rcv from:"<<source_id<< " local pid:"<<id_<<" rcv len:"<<len<<endl;
        //cout<<QString("rcv pid:%1, rcv msg：%2,rcvlen：%3").arg(source_id).arg(rcv_msg).arg(len).toStdString()<<endl;
    }
}

void TaskMpi::sendMsg(){
    int t_id=0;   
    QString msg=QString("hello world:%1").arg(id_);
    if (t_id!=id_)
    {
         cout<<"send msg - sid:"<<id_<<"  tid:"<<t_id<<endl;
         //MPI_Send(msg.toStdString().c_str(), msg.length(), MPI_CHAR, t_id, 99,MPI_COMM_WORLD); 
         MPI_Isend(msg.toStdString().c_str(), msg.length(), MPI_CHAR, t_id, 99,MPI_COMM_WORLD,&request_);//标准非阻塞发送
    }    
    
}

