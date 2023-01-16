#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sublib1.h"
#include "device.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
 
    
private:
    void initConnect();
    Ui::MainWindow *ui;

private slots:
    void slotLib1Clicked();
};
#endif // MAINWINDOW_H
