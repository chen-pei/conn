#include"myaddr.h"
MyAddr::MyAddr(const string host,unsigned short port) 
{
    sa.sin_family=AF_INET;
 
    sa.sin_addr.s_addr=(host.empty())?inet_addr("0"):inet_addr(host.c_str());
    sa.sin_port=(port==0)?htons(DEFALUTPORT):htons(port);
}

sockaddr*  MyAddr:: transtoaddr() 
{
    return reinterpret_cast<sockaddr*>(&sa);
}

int MyAddr::sizeofSa()
{
    return sizeof(sa);
}
MyAddr::~MyAddr()
{
}