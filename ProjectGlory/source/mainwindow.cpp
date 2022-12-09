#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QIcon>
// branch test20221209
MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    setWindowIcon(QIcon(":/resource/resources/ico.jpg"));    
    
}
MyMainWindow::~MyMainWindow()
{
    delete ui;
}

