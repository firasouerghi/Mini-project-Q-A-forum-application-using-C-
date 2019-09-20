#include "Category.h"

Category::Category()
{
    id = 0;
    title = "default";
    description = "default";
    isVisible = 0;
}

/* Getters */
int Category::getID(){return id;}
int Category::getStatus(){ return isVisible;}
string Category::getTitle() { return title;}
string Category::getDescription() { return description;}

/* Setters */
void Category::setDescription(string d){description = d;}
void Category::setID(int i){ id = i;}
void Category::setStatus(int st){ isVisible = st;}
void Category::setTitle(string t){ title = t;}

/* Methods for topics */
void Category::addTopic(Topic topic) { topics.push_back(topic);}
void Category::deleteTopic(int idTopic)
{
    int i = 0;
    while(idTopic!=topics[i].getID())
        i++;
    topics.erase(topics.begin()+i);
}
void Category::hideTopic(int idTopic)
{
    int i = 0;
    while(idTopic!=topics[i].getID())
        i++;
    topics[i].setStatus(0);
}

void Category::showTopic(int idTopic)
{
    int i = 0;
    while(idTopic!=topics[i].getID())
        i++;
    topics[i].setStatus(1);
}
void Category::editTopic(int idTopic, string newBody)
{
    int i = 0;
    while(idTopic!=topics[i].getID())
        i++;
    topics[i].setBody(newBody);
}
