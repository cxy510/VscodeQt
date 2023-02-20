
#ifndef __TABLEVIEW_SQL_H__
#define __TABLEVIEW_SQL_H__

#include "TableViewBase.h"
#include <QSqlTableModel>


class TableViewSQL:public TableViewBase
{    
    public:
        TableViewSQL(QTableView *tableview);
        ~TableViewBase();     
        //void insertData(QStringList stringlist);
        //void setRowData(int row,QStringList stringlist); 
    private:
        QSqlTableModel *model_sql_=NULL;
      
};

#endif
