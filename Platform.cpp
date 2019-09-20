#include "Platform.h"
#include "userProfile.h"
#include "Category.h"
Platform::Platform()
{
    //ctor
}

void Platform::addUser(userProfile up ){ users.push_back(up);}
void Platform::addCategory(Category cat){ categories.push_back(cat);}
void Platform::addAdmin(Admin admin){admins.push_back(admin);}
