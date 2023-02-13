#include "AnalyzeSqlite.h"

AnalyzeSqlite::AnalyzeSqlite(){
   //qDebug()<<"SQL:"<<QSqlDatabase::drivers();
}

AnalyzeSqlite::~AnalyzeSqlite(){

}

bool AnalyzeSqlite::openSqlite(QString connect_name,QString db_path){
    
    if(QSqlDatabase::contains(connect_name)){   //检测已连接的方式 - 自定义连接名
        db_ = QSqlDatabase::database(connect_name);
    }else{
        db_ = QSqlDatabase::addDatabase("QSQLITE",connect_name);
    }        
    
   
    db_.setDatabaseName(db_path); //设置数据库路径，不存在则创建
    
     if(!db_.open())
    {
        qDebug()<<"error: failed to connect sqlite3 database."<< db_.lastError();
        return false;
    }
    else {
        qDebug()<<"success to connect sqlite3 database.";
        return true;
    }


}

void AnalyzeSqlite::selectSqlite(const QString &query_msg){
    QSqlQuery sql_query;
    if(!sql_query.exec(query_msg)) {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"Query Size:"<<sql_query.size();
        while(sql_query.next())//判断下个查询数据是否可用
        {
            //ageValue=query.value(0).toInt();
        }
    }

}