#ifndef __ANALYZE_SQLITE_H__  
#define __ANALYZE_SQLITE_H__  
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>


class AnalyzeSqlite
{

public:
	AnalyzeSqlite();
	~AnalyzeSqlite();
    bool openSqlite(QString connect_name,QString db_path="");
    void selectSqlite(const QString &query_msg);
    
private:
    QSqlDatabase db_;
    QSqlQuery query_;
};

#endif