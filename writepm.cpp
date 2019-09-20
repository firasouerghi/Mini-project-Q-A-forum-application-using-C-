#include "writepm.h"
#include "ui_writepm.h"
#include "homepageforadmin.h"
#include "PrivateMessage.h"
#include "qmessagebox.h"
writepm::writepm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::writepm)
{
    ui->setupUi(this);
    for(unsigned i = 0 ; i < myPlatformFull.users.size();i++)
    {
        if(QString::fromUtf8(myPlatformFull.users[i].account.getUsername().c_str()) != session)
            ui->receiver->addItem(QString::fromUtf8(myPlatformFull.users[i].account.getUsername().c_str()));
    }
    for(unsigned j = 0; j < myPlatformFull.admins.size();j++)
    {
        if(QString::fromUtf8(myPlatformFull.admins[j].account.getUsername().c_str()) != session)
            ui->receiver->addItem(QString::fromUtf8(myPlatformFull.admins[j].account.getUsername().c_str()));
    }
}

writepm::~writepm()
{
    delete ui;
}

void writepm::on_homepagebutton_clicked()
{
    hide();
    homePageForAdmin hp;
    hp.setModal(true);
    hp.exec();
}

void writepm::on_Submit_clicked()
{

    QString title = ui->title->text();
    QString body = ui->topicBody->toPlainText();
    QString receiver = ui->receiver->currentText();
    if(!title.isEmpty() && !body.isEmpty() && !receiver.isEmpty())
    {
        int counter = 0;
        for(unsigned b = 0 ; b < myPlatformFull.users.size();b++)
        {
            for(unsigned c = 0 ; c < myPlatformFull.users[b].privateMessages.size();c++)
            {
                if(myPlatformFull.users[b].privateMessages[c].getID() >= counter)
                {
                    counter = myPlatformFull.users[b].privateMessages[c].getID() + 1;
                }
            }
        }
        for(unsigned d = 0 ; d < myPlatformFull.admins.size();d++)
        {
            for(unsigned e = 0 ; e < myPlatformFull.admins[d].privateMessages.size();e++)
            {
                if(myPlatformFull.admins[d].privateMessages[e].getID() >= counter)
                {
                    counter = myPlatformFull.admins[d].privateMessages[e].getID() + 1;
                }
            }
        }

        PrivateMessage pm;
        pm.setBody(body.toStdString());
        pm.setDate(currenDate.toString().toStdString());
        pm.setID(counter);
        pm.setReceiver(receiver.toStdString());
        pm.setSender(session.toStdString());
        pm.setTitle(title.toStdString());
        pm.setVisR(1);
        pm.setVisS(1);
        switch(rolesession)
        {
        case 0:
        {
            //adding pm to senders profile
            int x = -1;
            unsigned i =0;
            while(x == -1 && i<myPlatformFull.users.size())
            {
               if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                 x=i;
               i++;
            }
            myPlatformFull.users[x].addPM(pm);
            //adding pm to receivers profile
            // finding receiver : 'user' or 'admin'
            string streceiver = pm.getReceiver();
            int isnormaluser = -1;
            for(unsigned i = 0 ; i < myPlatformFull.users.size() ; i ++)
            {
                if(myPlatformFull.users[i].account.getUsername() == streceiver)
                    isnormaluser = i;
            }
            if(isnormaluser != -1)
            {
                myPlatformFull.users[isnormaluser].addPM(pm);

            }
            else
            {
                for(unsigned f=0;f<myPlatformFull.admins.size();f++)
                {
                    if(myPlatformFull.admins[f].account.getUsername() == streceiver)
                    {
                        myPlatformFull.admins[f].addPM(pm);
                        QMessageBox::about(this,"Message sent","Message sent successfully.");
                    }
                }
            }
            break;
        }
        case 1:
        {
            //adding pm to senders profile
            int x = -1;
            unsigned i =0;
            while(x == -1 && i<myPlatformFull.admins.size())
            {
               if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                 x=i;
               i++;
            }
            myPlatformFull.admins[x].addPM(pm);
            //adding pm to receivers profile
            // finding receiver : 'user' or 'admin'
            string streceiver = pm.getReceiver();
            int isnormaluser = -1;
            for(unsigned i = 0 ; i < myPlatformFull.users.size() ; i ++)
            {
                if(myPlatformFull.users[i].account.getUsername() == streceiver)
                    isnormaluser = i;
            }
            if(isnormaluser != -1)
            {
                myPlatformFull.users[isnormaluser].addPM(pm);

            }
            else
            {
                for(unsigned f=0;f<myPlatformFull.admins.size();f++)
                {
                    if(myPlatformFull.admins[f].account.getUsername() == streceiver)
                    {
                        myPlatformFull.admins[f].addPM(pm);
                        QMessageBox::about(this,"Message sent","Message sent successfully.");
                    }
                }
            }
            break;
        }
        default:
        {}
        }
    }
    else
    {
        QMessageBox::about(this,"Error","Empty fields not authorized.");
    }


}
