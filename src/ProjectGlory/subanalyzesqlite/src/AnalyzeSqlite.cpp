#include "AnalyzeSqlite.h"

AnalyzeSqlite::AnalyzeSqlite(){
   qDebug()<<"SQL:"<<QSqlDatabase::drivers();
}

AnalyzeSqlite::~AnalyzeSqlite(){
    closeSqlite();
}

bool AnalyzeSqlite::openSqlite(QString connect_name,QString db_path){
    db_.close();
    if(QSqlDatabase::contains(connect_name)){   //检测已连接的方式 - 自定义连接名
        db_ = QSqlDatabase::database(connect_name);
    }else{
        db_ = QSqlDatabase::addDatabase("QSQLITE",connect_name);//QSqlDatabase::addDatabase("QSQLITE",connect_name);
    }        
    
   
    db_.setDatabaseName(db_path); //设置数据库路径，不存在则创建
    
    qDebug()<<db_.driverName();
    qDebug()<<db_.databaseName();   

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

shared_ptr<QSqlQuery> AnalyzeSqlite::querySqlite(const QString &query_msg){   
    shared_ptr<QSqlQuery>query(new QSqlQuery(db_));   
    
    if(!query->exec(query_msg)) {
        qDebug()<<query->lastError();
        return NULL;
    }
    else
    {     
        // int loop=0;
        // while(query->next())//判断下个查询数据是否可用
        // {             
        //     qDebug()<<loop++<<":"<<query->value(0).toString()<<":"<<query->value(1).toString()<<":"<<query->value(2).toString();
        //     //ageValue=query.value(0).toInt();
        // }
    }
    return query;
}

int AnalyzeSqlite::getQueryRow(shared_ptr<QSqlQuery>get_query){
    int init_pos = get_query->at();
    // Very strange but for no records .at() returns -2
    int row = 0;
    if (get_query->last())
        row = get_query->at() + 1;
    else
        row = 0;
    // Important to restore initial pos
    get_query->seek(init_pos);
    return row;
}

 void AnalyzeSqlite::closeSqlite(){
    db_.close();
 }

const QSqlDatabase &AnalyzeSqlite::getDatabase(){
    return db_;
 }

// 加密数据库
 void AnalyzeSqlite::encryptSqlite(QString db_path){
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("SQLITECIPHER");
    dbconn.setDatabaseName(db_path);
    dbconn.setPassword("test");
    //将原本没有加密的数据库文件进行加密，此代码只需执行一次
    dbconn.setConnectOptions("QSQLITE_CREATE_KEY");
    qDebug()<<"is encrypt successful："<<dbconn.open();
    dbconn.close();
 }

// 解密密数据库
 void AnalyzeSqlite::decryptSqlite(QString db_path){
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("SQLITECIPHER");
    dbconn.setDatabaseName(db_path);
    dbconn.setPassword("test");
    //将原本没有加密的数据库文件进行加密，此代码只需执行一次
    dbconn.setConnectOptions("QSQLITE_UPDATE_KEY=");
    qDebug()<<"is decrypt successful："<<dbconn.open();
    dbconn.close();
 }