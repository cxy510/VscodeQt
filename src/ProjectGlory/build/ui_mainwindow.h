/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_conect;
    QPushButton *btn_send_tcp;
    QPushButton *btn_end_tcp;
    QPushButton *btn_begin_threadpool;
    QPushButton *btn_init_mpi_noblock;
    QPushButton *btn_send_mpi_noblock;
    QPushButton *btn_init_mpi_block;
    QLabel *lbl_mpi;
    QPushButton *btn_send_mpi;
    QPushButton *btn_end_mpi;
    QPushButton *btn_end_threadpool;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_str;
    QPushButton *btn_opensqlite;
    QPushButton *btn_encrypt;
    QPushButton *btn_decrypt;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_query;
    QPushButton *btn_query;
    QPushButton *btn_sql_model;
    QTableView *tableView;
    QWidget *tab_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_compress;
    QPushButton *btn_compress;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit__uncompress;
    QPushButton *btn_uncompress;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(744, 761);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 691, 59));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_conect = new QPushButton(layoutWidget);
        btn_conect->setObjectName(QStringLiteral("btn_conect"));

        horizontalLayout->addWidget(btn_conect);

        btn_send_tcp = new QPushButton(layoutWidget);
        btn_send_tcp->setObjectName(QStringLiteral("btn_send_tcp"));

        horizontalLayout->addWidget(btn_send_tcp);

        btn_end_tcp = new QPushButton(layoutWidget);
        btn_end_tcp->setObjectName(QStringLiteral("btn_end_tcp"));

        horizontalLayout->addWidget(btn_end_tcp);

        btn_begin_threadpool = new QPushButton(tab);
        btn_begin_threadpool->setObjectName(QStringLiteral("btn_begin_threadpool"));
        btn_begin_threadpool->setGeometry(QRect(10, 490, 187, 57));
        btn_init_mpi_noblock = new QPushButton(tab);
        btn_init_mpi_noblock->setObjectName(QStringLiteral("btn_init_mpi_noblock"));
        btn_init_mpi_noblock->setGeometry(QRect(80, 280, 187, 57));
        btn_send_mpi_noblock = new QPushButton(tab);
        btn_send_mpi_noblock->setObjectName(QStringLiteral("btn_send_mpi_noblock"));
        btn_send_mpi_noblock->setGeometry(QRect(330, 280, 187, 57));
        btn_init_mpi_block = new QPushButton(tab);
        btn_init_mpi_block->setObjectName(QStringLiteral("btn_init_mpi_block"));
        btn_init_mpi_block->setGeometry(QRect(80, 200, 187, 57));
        lbl_mpi = new QLabel(tab);
        lbl_mpi->setObjectName(QStringLiteral("lbl_mpi"));
        lbl_mpi->setGeometry(QRect(21, 141, 500, 30));
        lbl_mpi->setMinimumSize(QSize(500, 0));
        btn_send_mpi = new QPushButton(tab);
        btn_send_mpi->setObjectName(QStringLiteral("btn_send_mpi"));
        btn_send_mpi->setGeometry(QRect(330, 200, 187, 57));
        btn_end_mpi = new QPushButton(tab);
        btn_end_mpi->setObjectName(QStringLiteral("btn_end_mpi"));
        btn_end_mpi->setGeometry(QRect(550, 210, 187, 57));
        btn_end_threadpool = new QPushButton(tab);
        btn_end_threadpool->setObjectName(QStringLiteral("btn_end_threadpool"));
        btn_end_threadpool->setGeometry(QRect(390, 490, 187, 57));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_str = new QLineEdit(tab_2);
        lineEdit_str->setObjectName(QStringLiteral("lineEdit_str"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_str->sizePolicy().hasHeightForWidth());
        lineEdit_str->setSizePolicy(sizePolicy);
        lineEdit_str->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_2->addWidget(lineEdit_str);

        btn_opensqlite = new QPushButton(tab_2);
        btn_opensqlite->setObjectName(QStringLiteral("btn_opensqlite"));
        btn_opensqlite->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_2->addWidget(btn_opensqlite);

        btn_encrypt = new QPushButton(tab_2);
        btn_encrypt->setObjectName(QStringLiteral("btn_encrypt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_encrypt->sizePolicy().hasHeightForWidth());
        btn_encrypt->setSizePolicy(sizePolicy1);
        btn_encrypt->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(btn_encrypt);

        btn_decrypt = new QPushButton(tab_2);
        btn_decrypt->setObjectName(QStringLiteral("btn_decrypt"));
        sizePolicy1.setHeightForWidth(btn_decrypt->sizePolicy().hasHeightForWidth());
        btn_decrypt->setSizePolicy(sizePolicy1);
        btn_decrypt->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(btn_decrypt);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_query = new QLineEdit(tab_2);
        lineEdit_query->setObjectName(QStringLiteral("lineEdit_query"));
        sizePolicy.setHeightForWidth(lineEdit_query->sizePolicy().hasHeightForWidth());
        lineEdit_query->setSizePolicy(sizePolicy);
        lineEdit_query->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(lineEdit_query);

        btn_query = new QPushButton(tab_2);
        btn_query->setObjectName(QStringLiteral("btn_query"));
        btn_query->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(btn_query);

        btn_sql_model = new QPushButton(tab_2);
        btn_sql_model->setObjectName(QStringLiteral("btn_sql_model"));
        btn_sql_model->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(btn_sql_model);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 15);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 50, 651, 59));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_compress = new QLineEdit(layoutWidget1);
        lineEdit_compress->setObjectName(QStringLiteral("lineEdit_compress"));
        lineEdit_compress->setMinimumSize(QSize(0, 35));

        horizontalLayout_4->addWidget(lineEdit_compress);

        btn_compress = new QPushButton(layoutWidget1);
        btn_compress->setObjectName(QStringLiteral("btn_compress"));

        horizontalLayout_4->addWidget(btn_compress);

        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 150, 651, 59));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit__uncompress = new QLineEdit(layoutWidget2);
        lineEdit__uncompress->setObjectName(QStringLiteral("lineEdit__uncompress"));
        lineEdit__uncompress->setMinimumSize(QSize(0, 35));

        horizontalLayout_5->addWidget(lineEdit__uncompress);

        btn_uncompress = new QPushButton(layoutWidget2);
        btn_uncompress->setObjectName(QStringLiteral("btn_uncompress"));

        horizontalLayout_5->addWidget(btn_uncompress);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProjectGlory_V1.0.0.1", Q_NULLPTR));
        btn_conect->setText(QApplication::translate("MainWindow", "Connect TCP", Q_NULLPTR));
        btn_send_tcp->setText(QApplication::translate("MainWindow", "Send Tcp", Q_NULLPTR));
        btn_end_tcp->setText(QApplication::translate("MainWindow", "End Tcp", Q_NULLPTR));
        btn_begin_threadpool->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\347\272\277\347\250\213\346\261\240", Q_NULLPTR));
        btn_init_mpi_noblock->setText(QApplication::translate("MainWindow", "init Mpi no block", Q_NULLPTR));
        btn_send_mpi_noblock->setText(QApplication::translate("MainWindow", "send nnoblock msg", Q_NULLPTR));
        btn_init_mpi_block->setText(QApplication::translate("MainWindow", "init Mpi", Q_NULLPTR));
        lbl_mpi->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\345\217\267\357\274\232", Q_NULLPTR));
        btn_send_mpi->setText(QApplication::translate("MainWindow", "send msg", Q_NULLPTR));
        btn_end_mpi->setText(QApplication::translate("MainWindow", "End Mpi", Q_NULLPTR));
        btn_end_threadpool->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\272\277\347\250\213\346\261\240", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\351\200\232\344\277\241", Q_NULLPTR));
        lineEdit_str->setText(QApplication::translate("MainWindow", "D:\\TSP_Database.db", Q_NULLPTR));
        btn_opensqlite->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256", Q_NULLPTR));
        btn_encrypt->setText(QApplication::translate("MainWindow", "\345\212\240\345\257\206", Q_NULLPTR));
        btn_decrypt->setText(QApplication::translate("MainWindow", "\350\247\243\345\257\206", Q_NULLPTR));
        lineEdit_query->setText(QApplication::translate("MainWindow", "select * from secnum", Q_NULLPTR));
        btn_query->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        btn_sql_model->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\346\230\276\347\244\272", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\216\213\347\274\251\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        btn_compress->setText(QApplication::translate("MainWindow", "\345\216\213\347\274\251", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\216\213\347\274\251\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        btn_uncompress->setText(QApplication::translate("MainWindow", "\350\247\243\345\216\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\216\213\347\274\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
