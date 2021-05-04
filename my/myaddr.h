#ifndef MYADDR_H
#define MYADDR_H
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string>
#include<errno.h>
#include<cstdlib>
using namespace std;

const short DEFALUTPORT=5000;
class MyAddr
{
private:
    sockaddr_in sa;
public:
    MyAddr(string host="",unsigned short port=0);
     sockaddr* transtoaddr() ;
     int sizeofSa();
    ~MyAddr();
};






#endif