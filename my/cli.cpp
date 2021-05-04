#include<iostream>
#include"mytcp.h"
#include"myudp.h"
int main()
{

    MyAddr seradd("127.0.0.1",5001);
    MyUdp ser(seradd);
    MyUdp mu;
    mu.udpStart();
    while (true)
    {
        /* code */
        mu.sendMsg(ser,"hello");
        cout<<"send"<<endl;
    }    
    // MyAddr b("",5004);

    // MyTcp sertcp(ser);
    // MyTcp mytcp(b);
    // mytcp.tcpStart();
    // mytcp.testOut();
    // mytcp.myConnect(sertcp);
    // int a=0;
    
    //   mytcp.sendMsg("aaa");
    
  //  mytcp.setListen();
   // mytcp.myAccept(ntcp);
    //cout<<mytcp.isblock<<endl;
    //cout<<mytcp.sockfd<<endl;
    return 0;
    
}
