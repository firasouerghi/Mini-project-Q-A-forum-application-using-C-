#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <String>

using namespace std;
class Account
{
    public:
        Account();
        /* Setters */
        void setUsername(string un);
        void setEmail(string em);
        void setPassword(string pass);
        void setCreationDate(string dat);
        void setStatus(int st);
        /* Getters */
        string getUsername();
        string getPassword();
        string getEmail();
        string getCreationDate();
        int getStatus();
    private:
        string username;
        string email;
        string password;
        string creationDate;
        int isActive;
};

#endif // ACCOUNT_H
