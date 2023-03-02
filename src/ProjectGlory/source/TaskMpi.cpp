#include "TaskMpi.h"

TaskMpi::TaskMpi(QObject *parent):QObject(parent){
    int argc=10;
    char **argv;
    cout<<"Begin init"<< std::endl; 
    MPI_Init(&argc,&argv);    
    MPI_Comm_rank(MPI_COMM_WORLD, &id_);  
    //MPI_Comm_size(MPI_COMM_WORLD, &process_num_); 
    cout<<"id:"<<id_<<" size:"<<process_num_<< std::endl;      
}
TaskMpi::~TaskMpi(){
    cout<<"End Mpi id:"<<id_<<" size:"<<process_num_<< std::endl;   
    MPI_Finalize();
}

void TaskMpi::run_task(){
   //rcvDataBlock();
   rcvDataNotBlock();
   QThread::msleep(500);
}

int TaskMpi::getProcessId(){
    return id_;
}

 void TaskMpi::sendMsgBlock(){
    int t_id=0;   
    QString msg=QString("hello world:%1").arg(id_);
    if (t_id!=id_)
    {
         cout<<"send msg - sid:"<<id_<<"  tid:"<<t_id<<endl;
         MPI_Send(msg.toStdString().c_str(), msg.length(), MPI_CHAR, t_id, 99,MPI_COMM_WORLD);         
    }   
 }

void TaskMpi::sendMsgNotBlock(){
    int t_id=0;   
    int data = 555;
    MPI_Request request;
    //异步发送数据
    cout<<"block send"<<endl;
    MPI_Isend(&data, 1, MPI_INT, t_id, 99, MPI_COMM_WORLD, &request);
    printf("process %d send data, do other work\n", id_);

    //在多个request上等待
    MPI_Wait(&request, MPI_STATUSES_IGNORE);

    printf("process %d wait over\n", id_);

}

void TaskMpi::rcvDataBlock(){
    for (int source_id = 1; source_id < process_num_; source_id++) {
        char rcv_msg[100]={0};     
        cout<<"begin to rcv:"<<source_id<< " local pid:"<<id_<<endl;   
        int len=MPI_Recv(rcv_msg, 100, MPI_CHAR, source_id, 99,MPI_COMM_WORLD, &mpi_status_); // 阻塞接收        
        int count=0;		
		MPI_Get_count(&mpi_status_, MPI_CHAR, &count);
		 cout<<"rcv from:"<<source_id<< " local pid:"<<id_<<" rcv len:"<<count<<" rcv msg:"<<rcv_msg<<endl;
    }
}

void TaskMpi::rcvDataNotBlock(){
    for (int source_id = 1; source_id < process_num_; source_id++) {
        int data = 0;
		MPI_Request request;
		//异步接收数据
		MPI_Irecv(&data, 1, MPI_INT, source_id, 99, MPI_COMM_WORLD, &request);

		printf("process %d receive data,data is %d, do other work\n", id_, data);

		//在多个request上等待
		MPI_Status status;
		MPI_Wait(&request, &status);
		printf("process %d wait over, data is %d\n", id_, data);
    }
}