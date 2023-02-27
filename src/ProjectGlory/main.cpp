#include "mainwindow.h"
#include <QApplication>
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/mpi.hpp>
#include <iostream>
#include "mpi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.show();

    std::string line("Subject: Aw shell");
    boost::regex pat("^Subject: (Re: |Aw: )*(.*)");
    boost::gregorian::date d(2014, 1, 31);

    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
        std::cout << "MATCH: " << matches[2] << std::endl;


    int numprocs, myid, source;
    MPI_Status status;
    char message[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    return a.exec();
}
