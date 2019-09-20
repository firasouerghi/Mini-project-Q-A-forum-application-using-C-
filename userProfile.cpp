#include "userProfile.h"
#include <vector>

using namespace std;
userProfile::userProfile()
{
    name = "default";
    surname = "default";
    birthday = "default";
    occupation = "default";
    signature = "default";
    role = 0;
}

/* Getters */
string userProfile::getName(){ return name;}
string userProfile::getSurname(){ return surname;}
string userProfile::getBirthday() { return birthday;}
string userProfile::getOccupation() { return occupation;}
string userProfile::getSignature() { return signature;}
int userProfile::getRole() { return role;}

/* Setters */
void userProfile::setAccount(Account acc){account = acc;}
void userProfile::setName(string n){ name = n;}
void userProfile::setSurname(string sn) { surname = sn;}
void userProfile::setBirthday(string b) { birthday = b ; }
void userProfile::setOccupation(string oc) { occupation = oc;}
void userProfile::setSignature(string sig) { signature = sig;}
void userProfile::setRole(int ro) { role = ro;}

/* Methods for PMs */
void userProfile::deleteSentPM(int idPM)
{
    int i = 0;
    while(idPM!=privateMessages[i].getID())
        i++;
    privateMessages[i].setVisR(1);
    privateMessages[i].setVisS(0);
}

void userProfile::deleteReceivedPM(int idPM)
{
    int i = 0;
    while(idPM!=privateMessages[i].getID())
        i++;
    privateMessages[i].setVisR(0);
    privateMessages[i].setVisS(1);
}

void userProfile::addPM(PrivateMessage pm){ privateMessages.push_back(pm);}
