#include "showprofile.h"
#include "ui_showprofile.h"
#include "globalthings.h"
#include "homepageforadmin.h"
#include "homepageformember.h"
#include "qmessagebox.h"

showprofile::showprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showprofile)
{
    ui->setupUi(this);

    switch(rolesession)
    {
    case 0:
    {
        int x = -1;
        unsigned i = 0;
        while(i<myPlatformFull.users.size() && x == -1)
        {
            if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                x=i;
            i++;
        }
        ui->email->setPlaceholderText(QString::fromStdString(myPlatformFull.users[x].account.getEmail()));
        ui->name->setPlaceholderText(QString::fromStdString(myPlatformFull.users[x].getName()));
        ui->surname->setPlaceholderText(QString::fromStdString(myPlatformFull.users[x].getSurname()));
        ui->occupation->setPlaceholderText(QString::fromStdString(myPlatformFull.users[x].getOccupation()));
        ui->signature->setPlaceholderText(QString::fromStdString(myPlatformFull.users[x].getSignature()));
        break;
    }
    case 1:
    {
        int x = -1;
        unsigned i = 0;
        while(i<myPlatformFull.admins.size() && x == -1)
        {
            if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                x=i;
            i++;
        }
        ui->email->setPlaceholderText(QString::fromStdString(myPlatformFull.admins[x].account.getEmail()));
        ui->name->setPlaceholderText(QString::fromStdString(myPlatformFull.admins[x].getName()));
        ui->surname->setPlaceholderText(QString::fromStdString(myPlatformFull.admins[x].getSurname()));
        ui->occupation->setPlaceholderText(QString::fromStdString(myPlatformFull.admins[x].getOccupation()));
        ui->signature->setPlaceholderText(QString::fromStdString(myPlatformFull.admins[x].getSignature()));
        break;
    }
    default:
    {

    }
    }
}

showprofile::~showprofile()
{
    delete ui;
}

//return
void showprofile::on_inboxbutton_clicked()
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

//email
void showprofile::on_pushButton_2_clicked()
{
    if(!ui->email->text().isEmpty())
    {
        string stemail = ui->email->text().toStdString();
        int test = -1;
        for(unsigned i = 0 ; i < myPlatformFull.users.size();i++)
        {
            if(myPlatformFull.users[i].account.getEmail() == stemail)
                test = i;
        }
        for(unsigned j = 0 ; j < myPlatformFull.admins.size();j++)
        {
            if(myPlatformFull.users[j].account.getEmail() == stemail)
                test = j;
        }
        if(test != -1)
        {
            QMessageBox::about(this,"Error","Email Already Taken. Try another one.");
        }
        else
        {
            switch(rolesession)
            {
            case 0:
            {
                for(unsigned k = 0 ; k < myPlatformFull.users.size();k++)
                {
                    if(myPlatformFull.users[k].account.getUsername() == session.toStdString())
                    {
                        myPlatformFull.users[k].account.setEmail(stemail);
                        QMessageBox::about(this,"Done","Modification done.");
                    }
                }
                break;
            }
            case 1:
            {
                for(unsigned k = 0 ; k < myPlatformFull.admins.size();k++)
                {
                    if(myPlatformFull.admins[k].account.getUsername() == session.toStdString())
                    {
                        myPlatformFull.admins[k].account.setEmail(stemail);
                        QMessageBox::about(this,"Done","Modification done.");
                    }
                }
                break;
            }
            default:
            {}
            }
        }
    }
    else
    {
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }
}

//pass
void showprofile::on_pushButton_3_clicked()
{
    if(!ui->password->text().isEmpty())
    {
        string stpassword = ui->password->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].account.setPassword(stpassword);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].account.setPassword(stpassword);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }

}

//bday
void showprofile::on_pushButton_15_clicked()
{
    if(!ui->birthday->text().isEmpty())
    {
        string stbday = ui->birthday->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].setBirthday(stbday);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].setBirthday(stbday);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }


}

//name
void showprofile::on_pushButton_7_clicked()
{
    if(!ui->name->text().isEmpty())
    {
        string stname = ui->name->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].setName(stname);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].setName(stname);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }
}

//surname
void showprofile::on_pushButton_4_clicked()
{
    if(!ui->surname->text().isEmpty())
    {
        string stsurname = ui->surname->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].setSurname(stsurname);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].setSurname(stsurname);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }
}

//signature
void showprofile::on_pushButton_5_clicked()
{
    if(!ui->signature->text().isEmpty())
    {
        string stsig = ui->signature->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].setSignature(stsig);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].setSignature(stsig);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }
}

//occupation
void showprofile::on_pushButton_16_clicked()
{
    if(!ui->occupation->text().isEmpty())
    {
        string stocc = ui->occupation->text().toStdString();
        switch(rolesession)
        {
        case 0:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.users.size(); i++)
            {
                if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.users[i].setOccupation(stocc);
                    QMessageBox::about(this,"Done","Modification done.");

                }
            }
            break;
        }
        case 1:
        {
            for(unsigned i = 0 ;  i < myPlatformFull.admins.size(); i++)
            {
                if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
                {
                    myPlatformFull.admins[i].setOccupation(stocc);
                    QMessageBox::about(this,"Done","Modification done.");

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
        QMessageBox::about(this,"Error","Empty field not authorized.");
    }
}
