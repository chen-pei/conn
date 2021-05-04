#ifndef MESSAGE_H
#define MESSAGE_H
#include<stdint.h>
#include<string>
#include<arpa/inet.h>
#include<iostream>
#include<cstring>
using namespace std;
const  uint16_t VERIFY=32574;

enum TYPE
{
    M_LOGIN=1,
    M_PING,
    M_LIST,
    M_LOGOUT,
    M_PUNCH,
    M_TEXT,
    M_REPLY,
    M_INVALID
};

 struct head{
    uint16_t verify;
    TYPE type;//type of message
    uint32_t length;//length of message body
}__attribute__((packed));

typedef struct head Head;
class Message
{
private:
    Head head;
    string body;
public:
    Message();
    Message(const string &s);
    Message(const string &s,TYPE t);

    Message(const Message &m);

    void operator=(const Message&m);

    // out put all
    void printAll();

    //a Message class to net string
    string transToString();

    //a  net string to Message,if the message is invaild(verify!=VERIFY),return a message type is M_INVAILD 
    Message transToMessage(const string &s);

    ~Message();
};


#endif