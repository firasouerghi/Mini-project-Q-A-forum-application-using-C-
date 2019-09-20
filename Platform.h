#ifndef PLATFORM_H
#define PLATFORM_H


#include <vector>
#include "Category.h"
#include "userProfile.h"
#include "Admin.h"

using namespace std;
class Platform
{
    public:
        Platform();
        void addCategory(Category cat);
        void addUser(userProfile user);
        void addAdmin(Admin admin);
        vector<Category> categories;
        vector<userProfile> users;
        vector<Admin> admins;


};

#endif // PLATFORM_H
