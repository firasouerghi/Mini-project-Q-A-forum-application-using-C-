#include "Account.h"

Account::Account()
{
    username = "default";
    email = "default";
    password = "default";
    creationDate = "default";
    isActive = 0;
}

/* Setters */

void Account::setCreationDate(string d){ creationDate = d;}
void Account::setEmail(string em) { email = em;}
void Account::setPassword(string pass){ password = pass;}
void Account::setUsername(string un) { username = un;}
void Account::setStatus(int st) { isActive = st;}

/* Getters */
string Account::getCreationDate(){return creationDate;}
string Account::getEmail(){ return email;}
string Account::getPassword() { return password;}
string Account::getUsername() { return username;}
int Account::getStatus() { return isActive;}
