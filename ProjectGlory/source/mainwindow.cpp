#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QIcon>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    setWindowIcon(QIcon(":/resource/resources/ico.jpg"));    
    initConnect();    
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::initConnect(){
     connect(ui->btn_lib1,SIGNAL(clicked()),this,SLOT(slotLib1Clicked()));

}

void MyMainWindow::slotLib1Clicked(){
     sublib1 hi;
     hi.print();
     IDevice id1;
     id1.print();
}