#include "PrivateMessage.h"

PrivateMessage::PrivateMessage()
{
        id = 0;
        sender = "default";
        receiver = "default";
        title = "default";
        body = "default";
        date = "default";
        isVisibleForReceiver = 1;

}

/* Setters */

void PrivateMessage::setBody(string b){ body = b;}
void PrivateMessage::setDate(string d) { date = d;}
void PrivateMessage::setID(int i){ id = i;}
void PrivateMessage::setReceiver(string r) { receiver = r;}
void PrivateMessage::setSender(string s){ sender = s;}
void PrivateMessage::setTitle(string t){ title = t;}
void PrivateMessage::setVisR(int x) { isVisibleForReceiver = x;}
void PrivateMessage::setVisS(int x){ isVisibleForSender = x;}


/* Getters */
string PrivateMessage::getBody(){return body;}
string PrivateMessage::getDate(){return date;}
int PrivateMessage::getID() { return id;}
string PrivateMessage::getReceiver(){ return receiver;}
string PrivateMessage::getSender() { return sender;}
string PrivateMessage::getTitle() { return title;}
int PrivateMessage::getVisR() { return isVisibleForReceiver;}
int PrivateMessage::getVisS() { return isVisibleForSender;}
