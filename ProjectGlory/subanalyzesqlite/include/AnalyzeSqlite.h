#ifndef __ANALYZE_SQLITE_H__  
#define __ANALYZE_SQLITE_H__  
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <memory>
using namespace std;


class AnalyzeSqlite
{

public:
	AnalyzeSqlite();
	~AnalyzeSqlite();
    bool openSqlite(QString connect_name,QString db_path="");// 打开数据库
    shared_ptr<QSqlQuery> querySqlite(const QString &query_msg);// 查询
    int getQueryRow(shared_ptr<QSqlQuery>get_query); // 获取查询结果总数
    void closeSqlite();// 关闭数据库
    
private:
    QSqlDatabase db_;
};

#endif