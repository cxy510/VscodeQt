#include "mainwindow.h"
#include <QApplication>
//#include <boost/mpi.hpp>
#include <iostream>
#include "mpi/mpi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.show();

    int numprocs, myid, source;
    MPI_Status status;
    char message[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    if (myid != 0) {  //非0号进程发送消息
        strcpy(message, "Hello World!");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, 99,
            MPI_COMM_WORLD);
    }
    else {   // myid == 0，即0号进程接收消息
        for (source = 1; source < numprocs; source++) {
            MPI_Recv(message, 100, MPI_CHAR, source, 99,
                MPI_COMM_WORLD, &status);
            //printf("接收到第%d号进程发送的消息：%s\n", source, message);
            qDebug()<<QString("接收到第%d号进程发送的消息：%s\n").arg(source).arg(message);
        }
    }
    MPI_Finalize();
    return a.exec();
}
