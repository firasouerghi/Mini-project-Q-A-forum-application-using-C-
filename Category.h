#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include <Topic.h>

using namespace std;

class Category
{
    public:
        Category();
        /* Setters */
        void setID(int i);
        void setTitle(string t);
        void setDescription(string d);
        void setStatus(int st);
        /* Getters */
        int getID();
        int getStatus();
        string getTitle();
        string getDescription();
        /* Methods for topics */
        void addTopic(Topic topic);
        void deleteTopic(int idTopic);
        void editTopic(int idTopic, string bodyTopic);
        void hideTopic(int idTopic);
        void showTopic(int idTopic);
        /* Topics list : Should be public for later user */
        vector<Topic> topics;
    private:
        int id;
        string title;
        string description;
        int isVisible;
};

#endif // CATEGORY_H
