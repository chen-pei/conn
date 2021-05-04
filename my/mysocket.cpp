#include"mysocket.h"
MySocket::MySocket():myaddr(),sockfd(-1)
{
}

 MySocket::MySocket(const MyAddr &addr) :myaddr(addr),sockfd(-1)
 {
 }

void MySocket::initSocket(int type) 
{
    sockfd=socket(AF_INET,type,0);
    if(sockfd<0)
    {
        perror("socket") ;
        exit(EXIT_FAILURE);
       }
      int ret=bind(sockfd,myaddr.transtoaddr(),myaddr.sizeofSa());
      if(ret<0)
      {
          perror("bind");
          exit(EXIT_FAILURE);
      }
}

MySocket::~MySocket()
{
}
