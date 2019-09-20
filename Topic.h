#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <vector>
#include "Reply.h"

using namespace std;

class Topic
{
    public:
        Topic();
        /*Setters*/
        void setID(int i);
        void setStatus(int st);
        void setTitle(string t);
        void setBody(string b);
        void setAuthor(string a);
        void setDate(string d);
        void setCatID(int n);
        /*Getters*/
        int getID();
        int getStatus();
        string getTitle();
        string getBody();
        string getAuthor();
        string getDate();
        int getCatID();
        /*methods for replies*/
        void addReply(Reply reply);
        void deleteReply(int idReply);
        void editReply(int idReply, string newBody);
        void hideReply(int idReply);
        /* Replies list : Should be public for later user */
        vector<Reply> replies;

    private:
        int id;
        string title;
        string body;
        string author;
        string date;
        int isVisible;
        int catID;
};

#endif // TOPIC_H
