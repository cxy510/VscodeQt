
#ifndef __TABLEVIEW_SQL_H__
#define __TABLEVIEW_SQL_H__

#include "TableViewBase.h"
#include <QSqlTableModel>
#include <QSqlDatabase>



class TableViewSQL:public TableViewBase
{    
    public:
        TableViewSQL(QTableView *tableview,const QSqlDatabase&db);
        ~TableViewSQL();     
        void selectTable(QString table_name,QString str_filter);
        //void insertData(QStringList stringlist);
        //void setRowData(int row,QStringList stringlist); 
    private:
        QSqlTableModel *model_sql_=NULL;
      
};

#endif
