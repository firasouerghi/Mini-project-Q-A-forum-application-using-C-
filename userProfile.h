#ifndef USERPROFILE_H
#define USERPROFILE_H

#include "Account.h"
#include <string>
#include "PrivateMessage.h"
#include <vector>

using namespace std;

class userProfile
{
    public:
        userProfile();
        /* Getters */
        string getName();
        string getSurname();
        string getBirthday();
        string getOccupation();
        string getSignature();
        int getRole();
        /* Setters */
        void setAccount(Account acc);
        void setName(string n);
        void setSurname(string sn);
        void setBirthday(string b);
        void setOccupation(string oc);
        void setSignature(string sig);
        void setRole(int ro);
        /* Associated account : should be public for later use */
        Account account;
        /* Associated PMs : should be public for later use */
        vector<PrivateMessage> privateMessages;
        /* Methods for PMs */
        virtual void deleteSentPM(int idPM);
        void deleteReceivedPM(int idPM);
        void addPM(PrivateMessage pm);

    protected:
        string name;
        string surname;
        string birthday;
        string occupation;
        string signature;
        int role;
};

#endif // USERPROFILE_H
