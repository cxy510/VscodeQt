
#ifndef __TABLEVIEW_BASE_H__
#define __TABLEVIEW_BASE_H__

#include <QTableView>
#include <QAbstractTableModel>
#include <QHeaderView>

class TableViewBase
{    
    public:
        TableViewBase(QTableView *tableview,QAbstractTableModel *model);
        ~TableViewBase();     
        //void insertData(QStringList stringlist);
        //void setRowData(int row,QStringList stringlist); 

    private:
        virtual void initModel();
        QAbstractTableModel *model_=NULL;   
        QTableView *tableview_=NULL;
};

#endif
