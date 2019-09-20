#include "signupform.h"
#include "ui_signupform.h"
#include "landingpage.h"
#include "qmessagebox.h"
#include "dbqueries.h"
#include <QDebug>
#include "globalthings.h"
#include "Account.h"

signupform::signupform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupform)
{
    ui->setupUi(this);
}

signupform::~signupform()
{
    delete ui;
}

void signupform::on_backHome_clicked()
{
    alyncibi = 1;
    this->hide();
    LandingPage *homepage = new LandingPage();
    homepage->show();
}

void signupform::on_signupButton_clicked()
{

    QString userName = ui->usernameInput->text();
    QString passWord = ui->passwordInput->text();
    QString eMail = ui->emailInput->text();

    if(!userName.isEmpty() && !passWord.isEmpty() && !eMail.isEmpty())
    {
        int testUsername = 0;
        int testEmail = 0;

        unsigned i = 0;
        while(i<myPlatformFull.users.size() && testUsername == 0)
        {
            if(QString::fromUtf8(myPlatformFull.users[i].account.getUsername().c_str()) == userName)
            {
                testUsername = 1;
            }
            i++;
        }

        unsigned j = 0;
        while(j<myPlatformFull.admins.size() && testUsername == 0)
        {
            if(QString::fromUtf8(myPlatformFull.admins[j].account.getUsername().c_str()) == userName)
            {
                testUsername = 1;
            }
            j++;
        }

        unsigned k = 0;
        while(k<myPlatformFull.users.size() && testEmail == 0)
        {
            if(QString::fromUtf8(myPlatformFull.users[k].account.getEmail().c_str()) == eMail)
            {
                testEmail = 1;
            }
            k++;
        }

        unsigned l = 0;
        while(l<myPlatformFull.admins.size() && testEmail == 0)
        {
            if(QString::fromUtf8(myPlatformFull.admins[l].account.getEmail().c_str()) == eMail)
            {
                testEmail = 1;
            }
            l++;
        }

        if(testEmail == 0 && testUsername == 0)
        {
            Account newaccount;
            newaccount.setEmail(eMail.toStdString());
            newaccount.setPassword(passWord.toStdString());
            newaccount.setStatus(1);
            newaccount.setUsername(userName.toStdString());
            newaccount.setCreationDate(currenDate.toString().toStdString());

            userProfile newuserprofile;
            newuserprofile.setAccount(newaccount);
            newuserprofile.setRole(0);

            myPlatformFull.users.push_back(newuserprofile);

            QMessageBox::about(this,"Congrats !","Your account has been set correctly. Login and edit your personal details in Profile section.");

        }
        else if ( testEmail == 1 && testUsername == 0)
        {
            QMessageBox::about(this,"Oops ..","Choose another email address.");
        }
        else if (testEmail == 0 && testUsername == 1)
        {
            QMessageBox::about(this,"Oops ..", "Choose another username.");
        }
        else
        {
            QMessageBox::about(this,"Oops ..", "Username and Email already taken. Change both of them.");
        }

    }
    else
    {
        QMessageBox::about(this,"Important","All fields are mandatory.");
    }


}
