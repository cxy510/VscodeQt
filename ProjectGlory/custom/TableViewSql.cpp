#include "TableViewSql.h"

TableViewSQL::TableViewSQL(QTableView *tableview):tableview_(tableview){ 
     model_sql_=new QSqlTableModel;     
     model_=model_sql_;// 赋值基类
}

TableViewSQL::~TableViewSQL(){   
    
}
