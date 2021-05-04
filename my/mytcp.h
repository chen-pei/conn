#include"mysocket.h"
#include<iostream>
#include<sys/types.h>
#include<fcntl.h>
using namespace std;
class MyTcp:public MySocket
{
private:
    bool isblock;
public:
    MyTcp();
     MyTcp(const MyAddr &my);
    ~MyTcp();
    //test
    void testOut();
    //set listenqueue
    void setListen(unsigned int length=32);
    //set block
    void setblock(bool isblock);

    //accept ,the mt will get a socket 
    void myAccept(MyTcp &mt);

    //connect     give myaddr or MyTcp
    void myConnect(MyTcp &mt);   

    void myConnect(MyAddr &a);

    //bind start
    void tcpStart();

    //do this after connected 
    void sendMsg(const string msg);

    void recvMsg(string &s);
};

