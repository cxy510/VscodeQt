
#ifndef __TABLEVIEW_BASE_H__
#define __TABLEVIEW_BASE_H__

#include <QTableView>
#include <QAbstractTableModel>
#include <QHeaderView>
#include <QDebug>

class TableViewBase
{    
    public:
        TableViewBase(QTableView *tableview);
        virtual ~TableViewBase();   
        virtual void initModel();       
        //void insertData(QStringList stringlist);
        //void setRowData(int row,QStringList stringlist); 

    protected:
        QAbstractTableModel *model_=NULL;   
        QTableView *tableview_=NULL;

    private:
           
        
};

#endif
