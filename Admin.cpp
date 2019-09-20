#include "Admin.h"

void Admin::deleteSentPM(int idPM)
{
    int i = 0;
    while(idPM!=privateMessages[i].getID())
        i++;
    privateMessages[i].setVisR(0);
    privateMessages[i].setVisS(0);
}
