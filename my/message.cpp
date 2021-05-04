#include"message.h"
Message::Message(/* args */)
{
    head.type=M_PING;
    head.verify=VERIFY;

    head.length=sizeof(head.verify)+sizeof(head.type)+sizeof(head.length);
}
 Message::Message(const string &s):body(s)
{
     head.type=M_PING;
    head.verify=VERIFY;

    head.length=sizeof(head.verify)+sizeof(head.type)+sizeof(head.length)+s.length();
}

Message::Message(const string &s,TYPE t):body(s)
{
      head.type=t;
    head.verify=VERIFY;
    head.length=sizeof(head.verify)+sizeof(head.type)+sizeof(head.length)+s.length();
}

string Message::transToString()
{
    cout<<"type=:::::"<<head.type<<endl;
    char *buf=new char [1024];
    uint16_t m_magic = htons(head.verify);
	uint32_t m_type = htonl(head.type);
    cout<<"type=:::::"<<m_type<<endl;
	uint32_t m_length = htonl(head.length);

	int index = 0;
	memcpy(buf+index,&m_magic,sizeof(head.verify));
	index += sizeof(head.verify);
	memcpy(buf + index, &m_type, sizeof(head.type));
	index += sizeof(head.type);
	memcpy(buf + index, &m_length, sizeof(head.length));
	index += sizeof(head.length);
	memcpy(buf + index, body.c_str(), body.length());
    index+=sizeof(body.length());
    *(buf+index)='\0';
    // string s="";
    // s+=htons(head.verify)+htonl(head.type)+htonl(head.length);
    // s+=body;
   return string(buf);
}

 Message Message::transToMessage(const string &s)
{
       char *buf=const_cast<char*> (s.c_str());

       cout<<"buf:---"<<s.length()<<endl;
        int index = 0;
        //uint16_t*为两个字节的指针 解析magic
        uint16_t ve= ntohs(*(uint16_t*)(buf + index));
        index += sizeof(uint16_t);
        if (ve!= VERIFY)//不符合该报文格式 不用解析
        {
           cout<<"The message is invaild"<<endl;
           return Message("",M_INVALID);
        }
        //解析类型


        uint32_t ty = ntohl(*(uint32_t*)(buf + index));
        index += sizeof(uint32_t);


        //解析长度
        uint32_t len = ntohl(*(uint32_t*)(buf + index));
        index += sizeof(uint32_t);
        //解析body
        char *b = buf + index;
        cout<<"type:  -----"<<ty<<endl;
        return Message(string(b),TYPE(ty));













//     int index=0;
//     char *ts=const_cast<char*>(s.c_str());

//     // uint16_t ve=ntohs(*((uint16_t*)(ts+index)));
//     // cout<<"ve="<<ve<<endl;
//    uint16_t ve=ntohs(*(reinterpret_cast<uint16_t*>(const_cast<char *>(s.substr(index,sizeof(uint16_t)).c_str()))));
//     cout<<"ve="<<ve<<endl;
//     //invaild message,return a mesasage type is M_INVAILD
//     if(VERIFY!=ve)
//     {
//         cout<<"The Message is invaild"<<endl;
//         return Message("",M_INVALID);
//     }
//     index+=sizeof(uint16_t);


//     //uint32_t ty=ntohl(*((uint32_t*)(ts+index)));

//     uint32_t ty=ntohl(*(reinterpret_cast<uint32_t*>(const_cast<char *>(s.substr(index,sizeof(uint32_t)).c_str()))));
//     index+=sizeof(uint32_t);
//     cout<<"type= "<<ty<<endl;
//    // uint32_t len=ntohl(*((uint32_t*)(ts+index)));
//     uint32_t len=ntohl(*(reinterpret_cast<uint32_t*>(const_cast<char *>(s.substr(index,sizeof(uint32_t)).c_str()))));
//     index+=sizeof(uint32_t);
//     cout<<"len:"<<len<<endl;
//     string ns=s.substr(index,s.length());
//     return Message(ns,TYPE(ty));
}

 void Message::operator=(const Message&m)
    {
        body=m.body;
        head=m.head;
    }

void Message::printAll()
{
    cout<<"verify: "<<head.verify<<endl
            <<"type: "<<head.type<<endl
            <<"length: "<<head.length<<endl
            <<"body: "<<body<<endl;
}

Message::Message(const Message &m)
{
    this->body=m.body;
    this->head=m.head;
}

Message::~Message()
{
}
