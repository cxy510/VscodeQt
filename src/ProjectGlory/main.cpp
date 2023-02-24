#include "mainwindow.h"
#include <QApplication>
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>


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

    return a.exec();
}
