#include "mainwindow.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.show();

    int procs_id, procs_count, namelen;

    //返回的是进程的名字
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    /*
    该函数通常应该是第一个被调用的MPI函数用于并行环境初始化，
    其后面的代码到 MPI_Finalize()函数之前的代码在每个进程中都会被执行一次。
    */
    MPI_Init(&argc, &argv);   

    //得到本进程在通信空间中的rank值, 即在组中的逻辑编号(该 rank值为0到p - 1间的整数, 相当于进程的ID。)
    MPI_Comm_rank(MPI_COMM_WORLD, &procs_id);

    /*
        –  获得进程个数 size。
        –  指定一个通信子,也指定了一组共享该空间的进程, 这些进程组成该通信子的group（组）。
        –  获得通信子comm中规定的group包含的进程的数量。
    */
    MPI_Comm_size(MPI_COMM_WORLD, &procs_count);

    //参数描述：name为返回的机器名字符串，resultlen为返回的机器名长度
    MPI_Get_processor_name(processor_name, &namelen);

    if (procs_id == 0)
        printf("进程数目为: %d\n", procs_count);
    printf("进程%s说: Hello world 来自进程 %d \n", processor_name, procs_id);

    MPI_Finalize();
    return a.exec();
}
