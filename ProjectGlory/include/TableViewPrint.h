/**
 *  @file      IDevice.h
 *  @brief     通信设备模块
 *  @author    cxy(wuyuming510@139.com)
 *  @date      2023-1-16
 *  @copyright 
 */

#ifndef __TABLEVIEW_PRINT_H__
#define __TABLEVIEW_PRINT_H__

#include <QTableView>
#include <QStandardItemModel>
#include <QStringList>
#include <QHeaderView>

class TableViewPrint
{    
    public:
        TableViewPrint(QTableView *tableview);
        ~TableViewPrint();     
        void insertData(QStringList stringlist);
        void setRowData(int row,QStringList stringlist); 

    private:
        void initModel();
        QStandardItemModel *model_=new QStandardItemModel;   
        QTableView *tableview_=NULL;
        int col_num_=1;// 列数
};

#endif
