#ifndef ADMIN_H
#define ADMIN_H

#include "userProfile.h"

class Admin: public userProfile
{
    public:
        void deleteSentPM(int idPM);
};

#endif // ADMIN_H
