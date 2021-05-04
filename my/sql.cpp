#include"sql.h"
Sql::Sql():mysql(nullptr),res(nullptr)
{
    hostname="localhost";
    name="root";
    passwd="123456";
    database="mytest";
    port=3306;
}
Sql::Sql(const string &filename):mysql(nullptr),res(nullptr)
{
    fstream fs;
    fs.open(filename,ios::in);
    if(!fs.is_open())
    {
        Sql();
        return;
    }
    fs>>hostname
        >>name
        >>passwd
        >>database
        >>port;
    fs.close();
}




bool Sql::exeSql(const string &s)
{
    int ret=mysql_real_query(mysql,s.c_str(),s.length());
    res=mysql_store_result(mysql);
    return (ret==0)?true:false;
}

void Sql::initSql()
{
    mysql=mysql_init(nullptr);
    //connect    error
   if(!mysql_real_connect(mysql,hostname.c_str(),
    name.c_str(),
    passwd.c_str(),
    database.c_str(),port,NULL,0))
    {
        perror("mysql connect");
        exit(EXIT_FAILURE);
    }
}

    string ** Sql::getResult(int &l,int &c)
    {

         MYSQL_ROW row;
         int rnum=mysql_num_rows(res);//column num 
         int field_num=mysql_num_fields(res);//field num

         string **s= new string *[rnum];
         int count=0;

         //use mysql_fetch_row get  result >> s
        while(row=mysql_fetch_row(res))
        {
                string *temps=new string[field_num];
                for(int t=0;t<field_num;t++)  
                {  
                  temps[t]=row[t];
                }  
            s[count++]=temps;
         }   
        l=rnum;
        c=field_num;
        return s;
    }

    bool Sql::exeSqlFile(const string &filename)
    {
        fstream fs;
        fs.open(filename,ios::in);
        if(!fs.is_open())
        {
            return false;
        }

        //file eof
        char t;
        fs>>t;
        if(fs.eof())
        {
            return false;
        }
        fs.putback(t);

        //execute sql
        string s;
        while (getline(fs,s))
        {
            if(!exeSql(s))
            {
                return false;
            }
        }
        return true;
    }

    Sql::~Sql()
    {
        mysql_close(mysql);
        mysql_free_result(res);
    }