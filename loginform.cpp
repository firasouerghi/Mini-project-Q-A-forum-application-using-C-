#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>
#include "landingpage.h"
#include <QDialog>
#include "homepageforadmin.h"
#include "homepageformember.h"
#include "globalthings.h"
#include "dbqueries.h"

loginform::loginform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginform)
{
    ui->setupUi(this);

}

loginform::~loginform()
{
    delete ui;
}


void loginform::on_homeButton_clicked()
{
    alyncibi = 1;
    this->hide();
    LandingPage *homepage = new LandingPage();
    homepage->show();
}

void loginform::on_LoginButton_clicked()
{
    QString username = ui->inputUsername->text();
    QString password = ui->inputPassword->text();

    if(!username.isEmpty() && !password.isEmpty())
    {
        unsigned i = 0;
        while(
              i < myPlatformFull.users.size() &&
              !(
        (username.toStdString() == myPlatformFull.users[i].account.getUsername() &&
        password.toStdString() == myPlatformFull.users[i].account.getPassword() ) ||
        (username.toStdString() == myPlatformFull.users[i].account.getEmail() &&
         password.toStdString() == myPlatformFull.users[i].account.getPassword())
                  )
              )

        {i++;}

        if(i < myPlatformFull.users.size())
        {
            currentUser.setBirthday(myPlatformFull.users[i].getBirthday());
            currentUser.setName(myPlatformFull.users[i].getName());
            currentUser.setOccupation(myPlatformFull.users[i].getOccupation());
            currentUser.setRole(myPlatformFull.users[i].getRole());
            currentUser.setSignature(myPlatformFull.users[i].getSignature());
            currentUser.setSurname(myPlatformFull.users[i].getSurname());
            currentUser.account.setCreationDate(myPlatformFull.users[i].account.getCreationDate());
            currentUser.account.setEmail(myPlatformFull.users[i].account.getEmail());
            currentUser.account.setStatus(myPlatformFull.users[i].account.getStatus());
            currentUser.account.setUsername(myPlatformFull.users[i].account.getUsername());
            session = QString::fromUtf8(currentUser.account.getUsername().c_str());
            rolesession = 0;

            if(myPlatformFull.users[i].account.getStatus() != 0)
            {
                hide();
                homePageForMember hpm;
                hpm.setModal(true);
                hpm.exec();
            }


        }
        else
        {
            unsigned j = 0;
            while(
                  j < myPlatformFull.admins.size() &&
                  !(
            (username.toStdString() == myPlatformFull.admins[j].account.getUsername() &&
            password.toStdString() == myPlatformFull.admins[j].account.getPassword() ) ||
            (username.toStdString() == myPlatformFull.admins[j].account.getEmail() &&
             password.toStdString() == myPlatformFull.admins[j].account.getPassword())
                      )
                  )
            {j++;}
            if(j < myPlatformFull.admins.size())
            {
                currentUser.setBirthday(myPlatformFull.admins[j].getBirthday());
                currentUser.setName(myPlatformFull.admins[j].getName());
                currentUser.setOccupation(myPlatformFull.admins[j].getOccupation());
                currentUser.setRole(myPlatformFull.admins[j].getRole());
                currentUser.setSignature(myPlatformFull.admins[j].getSignature());
                currentUser.setSurname(myPlatformFull.admins[j].getSurname());
                currentUser.account.setCreationDate(myPlatformFull.admins[j].account.getCreationDate());
                currentUser.account.setEmail(myPlatformFull.admins[j].account.getEmail());
                currentUser.account.setStatus(myPlatformFull.admins[j].account.getStatus());
                currentUser.account.setUsername(myPlatformFull.admins[j].account.getUsername());
                session = QString::fromUtf8(currentUser.account.getUsername().c_str());
                rolesession = 1;
                if(myPlatformFull.admins[j].account.getStatus() != 0)
                {
                    hide();
                    homePageForAdmin hpma;
                    hpma.setModal(true);
                    hpma.exec();
                }

            }
            else
            {
                QMessageBox::about(this,"Oops ..","Incorrect login details.");
            }
        }
    }
    else
    {
        QMessageBox::about(this,"Empty fields","Inputs should be filled.");
    }

}
