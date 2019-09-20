#include "viewtopicwindow.h"
#include "ui_viewtopicwindow.h"
#include "globalthings.h"
#include "homepageforadmin.h"
#include "addreplypage.h"
#include "edittopicwindow.h"
#include "homepageformember.h"
#include "qsignalmapper.h"
#include "QDebug"

void ViewTopicWindow::ddo(int a)
{
    if(a<0)
    {
        for(unsigned i = 0 ; i < myPlatformFull.categories.size() ; i++)
        {
            for(unsigned j = 0 ; j < myPlatformFull.categories[i].topics.size() ; j++)
            {
                myPlatformFull.categories[i].topics[j].replies[-a].setStatus(1);
            }
        }
    }
    else
    {
        for(unsigned i = 0 ; i < myPlatformFull.categories.size() ; i++)
        {
            for(unsigned j = 0 ; j < myPlatformFull.categories[i].topics.size() ; j++)
            {
                myPlatformFull.categories[i].topics[j].replies[a].setStatus(0);
            }
        }
    }

}


ViewTopicWindow::ViewTopicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTopicWindow)
{
    ui->setupUi(this);
    if(rolesession == 0)
    {
        ui->pushButton_2->setVisible(false);
        ui->hidebutton->setVisible(false);
    }
    QString topic_body;
    QString topic_title;
    QString topic_author;
    QString topic_date;
    int topic_status = -2;

    for(unsigned i = 0; i<myPlatformFull.categories.size();i++)
    {
        for(unsigned j = 0 ; j < myPlatformFull.categories[i].topics.size(); j++ )
        {
            if(myPlatformFull.categories[i].topics[j].getID() == IDTopic)
            {

                topic_body = QString::fromUtf8(myPlatformFull.categories[i].topics[j].getBody().c_str());
                topic_title = QString::fromUtf8(myPlatformFull.categories[i].topics[j].getTitle().c_str());
                topic_author = QString::fromUtf8(myPlatformFull.categories[i].topics[j].getAuthor().c_str());
                if(rolesession == 0 && topic_author != session)
                {
                    ui->pushButton_3->setVisible(false);
                }
                topic_date = QString::fromUtf8(myPlatformFull.categories[i].topics[j].getDate().c_str());
                topic_status = myPlatformFull.categories[i].topics[j].getStatus();

                for(unsigned k = 0; k < myPlatformFull.categories[i].topics[j].replies.size();k++)
                {

                    if(rolesession == 1)
                    {

                        QLabel *replylabel = new QLabel();
                        QString reply_full = QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getBody().c_str())+
                                " by " +
                                QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getAuthor().c_str()) +
                                " on " + QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getDate().c_str());
                        replylabel->setText(reply_full);
                        replylabel->setStyleSheet("padding:10px 10px 10px 10px; background-color: #7f8c8d; font-weight: bold; color: #ecf0f1");
                        replylabel->setFixedWidth(550);
                        QPushButton *pushButtonn = new QPushButton();
                        int menu_x_pos = replylabel->pos().x();
                        int menu_y_pos = replylabel->pos().y();
                        pushButtonn->setGeometry(menu_x_pos+120, menu_y_pos,10,20);
                        if(myPlatformFull.categories[i].topics[j].replies[k].getStatus() == 0)
                        {
                            pushButtonn->setText("Show");
                        }
                        else
                        {
                             pushButtonn->setText("Hide");
                        }
                        pushButtonn->setStyleSheet("padding:10px 10px 10px 10px;background-color: #3498db");
                        ui->formLayout->insertRow(i,replylabel,pushButtonn);
                    }

                    else
                    {
                        if(myPlatformFull.categories[i].topics[j].replies[k].getStatus() != 0)
                        {
                            QLabel *replylabel = new QLabel();
                            QString reply_full = QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getBody().c_str())+
                                    " by " +
                                    QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getAuthor().c_str()) +
                                    " on " + QString::fromUtf8(myPlatformFull.categories[i].topics[j].replies[k].getDate().c_str());
                            replylabel->setText(reply_full);
                            replylabel->setStyleSheet("padding:10px 10px 10px 10px; background-color: #7f8c8d; font-weight: bold; color: #ecf0f1");
                            ui->formLayout->insertRow(i,replylabel);
                        }
                    }
                }
            }
        }
    }
    if(topic_status == 1)
    {
        ui->hidebutton->setText("Hide");
    }
    else
        ui->hidebutton->setText("Show");

    QString auth_name;
    QString auth_surname;
    QString auth_birthday;
    QString auth_signature;
    QString auth_occupation;
    switch(rolesession)
    {
    case 0:
    {
        for(unsigned i = 0 ; i < myPlatformFull.users.size() ; i++)
        {
            if(myPlatformFull.users[i].account.getUsername() == session.toStdString())
            {
                auth_birthday = QString::fromStdString(myPlatformFull.users[i].getBirthday());
                auth_name = QString::fromStdString(myPlatformFull.users[i].getName());
                auth_surname = QString::fromStdString(myPlatformFull.users[i].getSurname());
                auth_occupation = QString::fromStdString(myPlatformFull.users[i].getOccupation());
                auth_signature = QString::fromStdString(myPlatformFull.users[i].getSignature());
            }
        }
        break;
    }
    case 1:
    {
        for(unsigned i = 0 ; i < myPlatformFull.admins.size() ; i++)
        {
            if(myPlatformFull.admins[i].account.getUsername() == session.toStdString())
            {
                auth_birthday = QString::fromStdString(myPlatformFull.admins[i].getBirthday());
                auth_name = QString::fromStdString(myPlatformFull.admins[i].getName());
                auth_surname = QString::fromStdString(myPlatformFull.admins[i].getSurname());
                auth_occupation = QString::fromStdString(myPlatformFull.admins[i].getOccupation());
                auth_signature = QString::fromStdString(myPlatformFull.admins[i].getSignature());
            }
        }
        break;
    }
    default:
    {

    }
    }
    QString details = "Posted by : " + topic_author + ", on : " + topic_date + " | "+ auth_signature;
    QString details2 = "About author : " + auth_name + " " + auth_surname + " Born on : " + auth_birthday + ", " + auth_occupation;

    ui->detailslabel->setText(details);
    ui->detailslabel_2->setText(details2);
    ui->titlelabel->setText(topic_title);
    ui->topicbody->setText(topic_body);




}

ViewTopicWindow::~ViewTopicWindow()
{
    delete ui;
}

void ViewTopicWindow::on_pushButton_clicked()
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

void ViewTopicWindow::on_addReplyButton_clicked()
{
    hide();
    addReplyPage rpage;
    rpage.setModal(true);
    rpage.exec();

}


void ViewTopicWindow::on_pushButton_3_clicked()
{

    hide();
    editTopicWindow *editpage = new editTopicWindow;
    editpage->exec();

}


void ViewTopicWindow::on_pushButton_2_clicked()
{
    //delete topic section
    for(unsigned i = 0 ; i < myPlatformFull.categories.size() ; i++)
    {
        for(unsigned j = 0; j < myPlatformFull.categories[i].topics.size() ; j++)
        {
            if(myPlatformFull.categories[i].topics[j].getID() == IDTopic)
            {
                myPlatformFull.categories[i].deleteTopic(IDTopic);
                hide();
                homePageForAdmin hp;
                hp.setModal(true);
                hp.exec();
            }
        }
    }

}

void ViewTopicWindow::on_hidebutton_clicked()
{
    for(unsigned i = 0 ; i < myPlatformFull.categories.size() ; i++)
    {
        for(unsigned j = 0; j < myPlatformFull.categories[i].topics.size() ; j++)
        {
            if(myPlatformFull.categories[i].topics[j].getID() == IDTopic)
            {
                if(myPlatformFull.categories[i].topics[j].getStatus() == 1)
                {
                    myPlatformFull.categories[i].hideTopic(IDTopic);

                }
                else
                {
                    myPlatformFull.categories[i].showTopic(IDTopic);
                }
                hide();
                homePageForAdmin *hp = new homePageForAdmin;
                hp->exec();
            }
        }
    }

}
