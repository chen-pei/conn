#ifndef MYUDP_H
#define MYUDP_H
#include"mysocket.h"
#include<iostream>
#include<fcntl.h>
class MyUdp:public MySocket
{
private:
bool isblock;
public:
    MyUdp();
    MyUdp(const MyAddr &ma);

    //bind 
    void udpStart();

    void setblock(bool isblock);

     void sendMsg(MyUdp &mu,const string msg);

    void sendMsg(MyAddr &ma,const string msg);

    string recvMsg();
    
};

#endif