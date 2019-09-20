#ifndef PRIVATEMESSAGE_H
#define PRIVATEMESSAGE_H

#include <string>

using namespace std;

class PrivateMessage
{
    public:
        PrivateMessage();
        /* Getters */
        int getID();
        string getSender();
        string getReceiver();
        string getTitle();
        string getBody();
        string getDate();
        int getVisR();
        int getVisS();
        /* Setters */
        void setID( int i);
        void setSender(string s);
        void setReceiver(string r);
        void setTitle(string t);
        void setBody(string b);
        void setDate(string d);
        void setVisR(int x);
        void setVisS(int x);


    private:
        int id;
        int isVisibleForReceiver;
        int isVisibleForSender;
        string sender;
        string receiver;
        string title;
        string body;
        string date;
};

#endif // PRIVATEMESSAGE_H
