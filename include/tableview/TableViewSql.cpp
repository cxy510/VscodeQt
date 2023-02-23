#include <QSqlError>
#include "TableViewSql.h"

TableViewSQL::TableViewSQL(QTableView *tableview,const QSqlDatabase&db):TableViewBase(tableview){ 
     model_sql_=new QSqlTableModel(NULL,db);     
     model_=model_sql_;// 赋值基类
     initModel();  
}

TableViewSQL::~TableViewSQL(){   
    
}

void TableViewSQL::selectTable(QString table_name,QString str_filter){
    model_sql_->setTable(table_name);
    model_sql_->setEditStrategy(QSqlTableModel::OnManualSubmit); 

    model_sql_->setFilter(str_filter);// 条件查询

     //查询数据
    if(!model_sql_->select())
    {
        qDebug()<<"select table:"<<model_sql_->lastError();
        return;
    }
}