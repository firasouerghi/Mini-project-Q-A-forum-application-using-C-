#include "repliespage.h"
#include "ui_repliespage.h"
#include "globalthings.h"
#include "PrivateMessage.h"
#include "homepageforadmin.h"
#include <QDebug>
#include <QMessageBox>
#include "QSignalMapper"
#include "homepageformember.h"
#include "writepm.h"
void repliespage::dothing(int a)
{
    switch(rolesession)
    {
    case 0://normal user
    {
        //Sender or Receiver ?
        //first, getting an index to user => x
        int x = -1;
        unsigned i = 0;
        while(x == -1 && i < myPlatformFull.users.size())
        {
            if(QString::fromStdString(myPlatformFull.users[i].account.getUsername()) == session)
                x=i;
            i++;
        }

        //second, checking if the pm is sent or received
        int isSent = 0;
        int isReceived = 0;
        int j = 0;
        int test = 0;
        while(test == 0 && j<myPlatformFull.users[x].privateMessages.size())
        {
            if(myPlatformFull.users[x].privateMessages[j].getID() == a)
            {
                if(myPlatformFull.users[x].privateMessages[j].getSender() == session.toStdString())
                {
                    isSent = 1;
                    isReceived = 0;
                    test = isSent + isReceived;
                }
                else
                {
                    isSent = 0;
                    isReceived = 1;
                    test = isSent + isReceived;
                }
            }
            j++;
        }

        //acting, according to previous result
        if(isSent == 1)
        {
            myPlatformFull.users[x].deleteSentPM(a);
            this->hide();
            homePageForMember hp;
            hp.setModal(true);
            hp.exec();
        }
        else
        {
            myPlatformFull.users[x].deleteReceivedPM(a);
            this->hide();
            homePageForMember hp;
            hp.setModal(true);
            hp.exec();
        }
        break;
    }
    case 1://admin
    {
        //Sender or Receiver ?
        //first, getting an index to user => x
        int x = -1;
        unsigned i = 0;
        while(x == -1 && i < myPlatformFull.admins.size())
        {
            if(QString::fromStdString(myPlatformFull.admins[i].account.getUsername()) == session)
                x=i;
            i++;
        }

        //second, checking if the pm is sent or received
        int isSent = 0;
        int isReceived = 0;
        int j = 0;
        int test = 0;
        while(test == 0 && j<myPlatformFull.admins[x].privateMessages.size())
        {
            if(myPlatformFull.admins[x].privateMessages[j].getID() == a)
            {
                if(myPlatformFull.admins[x].privateMessages[j].getSender() == session.toStdString())
                {
                    isSent = 1;
                    isReceived = 0;
                    test = isSent + isReceived;
                }
                else
                {
                    isSent = 0;
                    isReceived = 1;
                    test = isSent + isReceived;
                }
            }
            j++;
        }

        //acting, according to previous result
        if(isSent == 1)
        {
            myPlatformFull.admins[x].deleteSentPM(a);
            this->hide();
            homePageForAdmin hp;
            hp.setModal(true);
            hp.exec();
        }
        else if(isReceived == 1)
        {
            myPlatformFull.admins[x].deleteReceivedPM(a);
            this->hide();
            homePageForAdmin hp;
            hp.setModal(true);
            hp.exec();
        }
        break;
    }
    default:
    {

    }
    }
}

repliespage::repliespage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::repliespage)
{
    ui->setupUi(this);
    //retrieving valid pms
    vector<PrivateMessage> mypms;
    switch(rolesession)
    {
    case 0:
    {
        //getting and index to user
        unsigned i = 0;
        int x = -1;
        while(x == -1 && i< myPlatformFull.users.size())
        {
            if(QString::fromUtf8((myPlatformFull.users[i].account.getUsername()).c_str()) == session)
            {
                x=i;
            }
            i++;
        }
        for(unsigned j = 0 ; j < myPlatformFull.users[x].privateMessages.size();j++)
        {
            //the user is sender
            if(QString::fromStdString(myPlatformFull.users[x].privateMessages[j].getSender()) == session)
            {
                //the message is visible for sender
                if(myPlatformFull.users[x].privateMessages[j].getVisS() == 1)
                    mypms.push_back(myPlatformFull.users[x].privateMessages[j]);
            }
            //else, the user is receiver
            else
            {
                //the message is visible for receiver
                if(myPlatformFull.users[x].privateMessages[j].getVisR() == 1)
                    mypms.push_back(myPlatformFull.users[x].privateMessages[j]);
            }
        }
        break;
    }
    case 1:
    {
        //getting and index to admin
        unsigned i = 0;
        int x = -1;
        while(x == -1 && i< myPlatformFull.admins.size())
        {
            if(QString::fromUtf8((myPlatformFull.admins[i].account.getUsername()).c_str()) == session)
            {
                x=i;
            }
            i++;
        }
        for(unsigned j = 0 ; j < myPlatformFull.admins[x].privateMessages.size();j++)
        {
            //the admin is sender
            if(QString::fromStdString(myPlatformFull.admins[x].privateMessages[j].getSender()) == session)
            {
                //the message is visible for sender
                if(myPlatformFull.admins[x].privateMessages[j].getVisS() == 1)
                    mypms.push_back(myPlatformFull.admins[x].privateMessages[j]);
            }
            //else, the admin is receiver
            else
            {
                //the message is visible for receiver
                if(myPlatformFull.admins[x].privateMessages[j].getVisR() == 1)
                    mypms.push_back(myPlatformFull.admins[x].privateMessages[j]);
            }
        }
        break;
    }
    default:{}
    }

    if(mypms.size() > 0 )
    {
        QSignalMapper* signalMapper = new QSignalMapper (this) ;
        for(unsigned i = 0 ; i < mypms.size() ; i++)
        {
            QString qstr = QString::fromStdString(mypms[i].getTitle()) +
                    " - From " +
                    QString::fromStdString(mypms[i].getSender()) +
                    " to " +
                    QString::fromStdString(mypms[i].getReceiver()) +
                    " on " +
                    QString::fromStdString(mypms[i].getDate()) +
                    " --- [" +
                    QString::fromStdString(mypms[i].getBody()) + "].";

            QLabel* ql = new QLabel();
            ql->setText(qstr);
            ql->setStyleSheet("padding:10px 10px 10px 10px; background-color: #7f8c8d; font-weight: bold; color: #ecf0f1");
            ql->setFixedWidth(570);

            QPushButton *pushbdelete = new QPushButton();
            int menu_x_pos = ql->pos().x();
            int menu_y_pos = ql->pos().y();
            pushbdelete->setGeometry(menu_x_pos+120, menu_y_pos,10,20);
            pushbdelete->setText("[X]");
            pushbdelete->setStyleSheet("padding:10px 10px 10px 10px;background-color: red");

            ui->formLayout->insertRow(i,ql,pushbdelete);
            connect (pushbdelete, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
            signalMapper->setMapping(pushbdelete, mypms[i].getID()) ;
        }
        connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(dothing(int))) ;
    }
}

repliespage::~repliespage()
{
    delete ui;
}

void repliespage::on_homebutton_clicked()
{
    if(rolesession == 1)
    {
        hide();
        homePageForAdmin hp;
        hp.setModal(true);
        hp.exec();
    }
    else
    {
        hide();
        homePageForMember hpm;
        hpm.setModal(true);
        hpm.exec();
    }
}

void repliespage::on_createbutton_clicked()
{
    hide();
    writepm wpm;
    wpm.setModal(true);
    wpm.exec();

}
