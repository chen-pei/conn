#ifndef MYSOCKET_H
#define MYSOCKET_H

const int TCP=1;
const int UDP=2;
#include"myaddr.h"
const int BUFSIZE=1024;
class MySocket
{
protected:
    MyAddr myaddr;
    int sockfd;
public:
    MySocket();
    MySocket(const MyAddr &addr);
    ~MySocket();
    void initSocket(int type);
};




#endif