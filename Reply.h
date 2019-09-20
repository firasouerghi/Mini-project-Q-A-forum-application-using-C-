#ifndef REPLY_H
#define REPLY_H
#include <string>

using namespace std;

class Reply
{
    public:
        Reply();
        void setID(int i);
        void setStatus(int st);
        void setBody(string b);
        void setAuthor(string a);
        void setDate(string d);
        void setTopicID(int n);
        string getBody();
        string getAuthor();
        string getDate();
        int getStatus();
        int getID();
        int getTopicID();

    private:
        int id;
        string body;
        string author;
        string date;
        int isVisible;
        int topicID;

};

#endif // REPLY_H
