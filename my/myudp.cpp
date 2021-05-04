#include"myudp.h"

MyUdp::MyUdp():isblock(true),MySocket()
{
}

    MyUdp::MyUdp(const MyAddr &ma):isblock(true),MySocket(ma)
    {
    }

    void MyUdp::udpStart()
    {
        this->initSocket(UDP);
    }

    void MyUdp::setblock(bool isblock)
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
  void MyUdp::sendMsg(MyUdp &mu,const string msg)
  {
      sendto(sockfd,msg.c_str(),sizeof(msg.c_str()),MSG_DONTWAIT,mu.myaddr.transtoaddr(),mu.myaddr.sizeofSa());
  }

void MyUdp::sendMsg(MyAddr &ma,const string msg)
{
          sendto(sockfd,msg.c_str(),sizeof(msg.c_str()),MSG_DONTWAIT,ma.transtoaddr(),ma.sizeofSa());
}

    string MyUdp::recvMsg()
    {
        char buf[BUFSIZE];
        int count;
        if(isblock)
        {
            count=recvfrom(sockfd,buf,BUFSIZE,0,NULL,NULL);
        }
        else{
            count=recvfrom(sockfd,buf,BUFSIZE,MSG_DONTWAIT,NULL,NULL);
        }
        buf[count]='\0';
        std::cout<<"recv msg"<<std::endl;
        string s(buf);
        return s;
    }
