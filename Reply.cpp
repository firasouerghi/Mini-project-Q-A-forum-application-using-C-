#include "Reply.h"

Reply::Reply()
{
    id = 0;
    body = "default";
    author = "default";
    date = "default";
    isVisible = 0;
}


string Reply::getAuthor(){return author;}
string Reply::getBody(){return body;}
string Reply::getDate(){return date;}
int Reply::getID(){return id;}
int Reply::getStatus(){return isVisible;}
int Reply::getTopicID(){return topicID;}

void Reply::setTopicID(int n){topicID = n;}
void Reply::setID(int i){id=i;}
void Reply::setStatus(int st){isVisible = st;}
void Reply::setBody(string b){body = b;}
void Reply::setAuthor(string a){author = a;}
void Reply::setDate(string d){date = d;}
