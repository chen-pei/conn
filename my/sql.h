#ifndef SQL_H
#define SQL_H
#include</usr/include/mysql/mysql.h>
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
class Sql
{
private:
    string hostname;
    string name;
    string passwd;
    string database;
    unsigned short port;
    MYSQL *mysql;
    MYSQL_RES *res;
public:
    Sql();
    ~Sql();
    //give a sql filename to create sql
    Sql(const string &filename);
    //execute a sql,if the sql error return  false
    bool exeSql(const string &s);

    //execute a sql file.
    bool exeSqlFile(const string &filename);

    //initialize mysqlconnect
    void initSql();

    //Get the result after  use exeSql ,return a string **  storaged result, two parameter are line and column.
      string ** getResult(int &l,int &c);


};




#endif