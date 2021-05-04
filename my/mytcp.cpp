#include"mytcp.h"
MyTcp::MyTcp():MySocket(),isblock(true)
{
  //  this->initSocket(TCP);
}
MyTcp::MyTcp(const MyAddr &my):MySocket(my),isblock(true)
{
    //this->initSocket(TCP);
}

MyTcp::~MyTcp()
{
}

void MyTcp::setListen(unsigned int length)
{
    if(::listen(sockfd,length)<0)
    {
        perror("listen");
        exit(EXIT_FAILURE);    
        }
}

void MyTcp::setblock(bool isblock)
{
    this->isblock=isblock;
    if(!isblock)//non-block
            {
                int flag=fcntl(sockfd,F_GETFL,0);
                if(flag<0)
                {
                    perror("fcntl get");
                    return;
                }
                if(fcntl(sockfd,F_SETFL,flag|O_NONBLOCK)<0)
                {
                    perror("fcntl set");
                    return;
                }
}
}
void MyTcp::myAccept(MyTcp &mt)
{
    //block
    if(isblock)
    {
        mt.sockfd=::accept(sockfd,NULL,NULL);
    }
    cout<<"hava a new cli"<<endl;
    //select or epoll
}


void MyTcp::myConnect(MyTcp &mt)
{
        if(::connect(sockfd,mt.myaddr.transtoaddr(),mt.myaddr.sizeofSa())<0)
        {
            perror("connect");
            exit(EXIT_FAILURE);
        }
} 

void MyTcp::testOut()
{
	cout<<"isblock="<<isblock<<endl;
	cout<<"sockfd"<<sockfd<<endl;
}

void MyTcp::myConnect(MyAddr &a)
{
      if(::connect(sockfd,a.transtoaddr(),a.sizeofSa()<0))
        {
            perror("connect");
            exit(EXIT_FAILURE);
        }
}

void MyTcp::tcpStart()
{
    this->initSocket(TCP);
}

void MyTcp::sendMsg( const string msg)
{
    send(sockfd,msg.c_str(),sizeof(msg.c_str()),0);
}

void MyTcp::recvMsg(string &s)
{
    char *buf;
    int ret=recv(sockfd,buf,BUFSIZE,0);
    if(ret<0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    s.clear();
    s.assign(buf);
}