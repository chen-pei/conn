#include<iostream>
//#include"mytcp.h"
#include<sys/types.h>
#include<unistd.h>
//#include"myudp.h"
//#include"sql.h"
#include"message.h"
int main()
{
  string s="adasdas";
  Message m(s,M_LOGOUT);
  string ts=m.transToString();
  Message n=m.transToMessage(ts);
  n.printAll();
  return 0;
    
}
