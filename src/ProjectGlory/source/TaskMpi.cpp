#include "TaskMpi.h"

TaskMpi::TaskMpi(BlockType block_type,QObject *parent):QObject(parent){
    block_type_=block_type;
    if (block_type_==kIsBlock)  {
        initMpiBlcok();
    }
    else if (block_type_==kNotBlcok)
    {
       initMpiNotBlock();
    }
    
  
}
TaskMpi::~TaskMpi(){
    cout<<"End Mpi id:"<<id_<<" size:"<<process_num_<< std::endl;   
    MPI_Finalize();
}

void TaskMpi::initMpiBlcok(){
   int argc=10;
    char **argv;
    cout<<"Begin Block init"<< std::endl; 
    MPI_Init(&argc,&argv);    
    MPI_Comm_rank(MPI_COMM_WORLD, &id_);  
    MPI_Comm_size(MPI_COMM_WORLD, &process_num_); 
    cout<<"id:"<<id_<<" size:"<<process_num_<< std::endl;      
}

void TaskMpi::initMpiNotBlock(){
    int argc=10;
    char **argv;
    cout<<"Begin Not Block init"<< std::endl; 
    MPI_Init(0,0);    
    MPI_Comm_rank(MPI_COMM_WORLD, &id_);  
    MPI_Comm_size(MPI_COMM_WORLD, &process_num_); 
    cout<<"id:"<<id_<<" size:"<<process_num_<< std::endl;     
}

void TaskMpi::run_task(){
    if(block_type_==kIsBlock){
        rcvDataBlock();
    }
    else if (block_type_==kNotBlcok)
    {
        rcvDataNotBlock();
    }
   
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
         cout<<"*****1block send msg - sid:"<<id_<<"  tid:"<<t_id<<endl;
         MPI_Send(msg.toStdString().c_str(), msg.length(), MPI_CHAR, t_id, 99,MPI_COMM_WORLD);         
         cout<<"*****2block send msg - sid:"<<id_<<"  tid:"<<t_id<<endl;
    }   
 }

void TaskMpi::sendMsgNotBlock(){
    int t_id=0;   
    int data = 555;
    MPI_Request request; 
    cout<<"*****1begin to send local id:"<<id_<<endl;  
    MPI_Isend(&data, 1, MPI_INT, t_id, 99, MPI_COMM_WORLD, &request);        
    cout<<"*****2have sended local id:"<<id_<<endl;
    //在多个request上等待
    //在多个request上等待
	//MPI_Waitall(100, request, MPI_STATUSES_IGNORE);
    MPI_Wait(&request, MPI_STATUSES_IGNORE);
     cout<<"*****3wait over:"<<id_<<endl;

}

void TaskMpi::rcvDataBlock(){
    for (int source_id = 1; source_id < process_num_; source_id++) {
        char rcv_msg[100]={0};     
        cout<<"====1rcv from id:"<<source_id<< " local pid:"<<id_<<endl;   
        int len=MPI_Recv(rcv_msg, 100, MPI_CHAR, source_id, 99,MPI_COMM_WORLD, &mpi_status_); // 阻塞接收        
        int count=0;		
		MPI_Get_count(&mpi_status_, MPI_CHAR, &count);
		 cout<<"====2rcv from:"<<source_id<< " local pid:"<<id_<<" rcv len:"<<count<<" rcv msg:"<<rcv_msg<<endl;
    }
}

void TaskMpi::rcvDataNotBlock(){
   for (int source_id = 1; source_id < process_num_; source_id++) {      
        int data = 0;       
		MPI_Request request;
        cout<<"====1rcv from id:"<<source_id<< " local pid:"<<id_<<endl;  
		//异步接收数据
		MPI_Irecv(&data, 1, MPI_INT, source_id, 99, MPI_COMM_WORLD, &request);  
        cout<<"====2rcv from:"<<source_id<< " local pid:"<<id_<<endl;
		//在多个request上等待
		MPI_Status status;
		MPI_Wait(&request, &status);
        cout<<"====3rcv from:"<<source_id<< " local pid:"<<id_<<"rcv msg:"<<data<<endl;
		
    }
}