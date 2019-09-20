#include "Topic.h"

Topic::Topic()
{
    id = 0;
    title = "default";
    body = "default";
    author = "defualt";
    date = "default";
    isVisible = 0;
}

/* Setters */
void Topic::setID(int i){ id = i;}
void Topic::setStatus(int st){ isVisible = st;}
void Topic::setTitle(string t){ title = t;}
void Topic::setBody(string b){ body = b;}
void Topic::setAuthor(string a){ author = a;}
void Topic::setDate(string d){date = d;}
void Topic::setCatID(int n){catID = n;}

/* Getters */
int Topic::getID(){ return id;}
int Topic::getStatus(){ return isVisible;}
string Topic::getTitle() { return title;}
string Topic::getBody() { return body;}
string Topic::getAuthor() { return author;}
string Topic::getDate(){return date;}
int Topic::getCatID(){return catID;}

/* Methods for replies */
void Topic::addReply(Reply reply) {replies.push_back(reply);}

void Topic::deleteReply(int idReply)
{
    int i = 0;
    while(idReply!=replies[i].getID())
        i++;
    replies.erase(replies.begin() + i);
}
void Topic::editReply(int idReply, string newBody)
{
    int i = 0;
    while(idReply!=replies[i].getID())
        i++;
    replies[i].setBody(newBody);
}
void Topic::hideReply(int idReply)
{
    int i = 0;
    while(idReply!=replies[i].getID())
        i++;
    replies[i].setStatus(0);
}

