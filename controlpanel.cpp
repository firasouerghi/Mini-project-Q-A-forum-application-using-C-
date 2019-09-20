#include "controlpanel.h"
#include "ui_controlpanel.h"
#include <QPixmap>
#include "homepageforadmin.h"
#include "loginform.h"
#include <QDebug>
#include <QMessageBox>

controlPanel::controlPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::controlPanel)
{
    ui->setupUi(this);
    QPixmap cat_img("img/category.png");
    QPixmap member_img("img/signup.png");

    int num_users = myPlatformFull.users.size() + myPlatformFull.admins.size();
    int num_cats = myPlatformFull.categories.size();
    int num_topics = 0;
    for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
    {
        num_topics += myPlatformFull.categories[i].topics.size();

    }

    int num_replies = 0 ;
    for(unsigned j = 0 ;  j < myPlatformFull.categories.size(); j++)
    {
        for(unsigned l = 0 ; l < myPlatformFull.categories[j].topics.size();l++)
        {
           num_replies += myPlatformFull.categories[j].topics[l].replies.size();
        }
    }


    QString su = QString::number(num_users);
    ui->nusers->setText(su);

    QString sc = QString::number(num_cats);
    ui->ncats->setText(sc);

    QString st = QString::number(num_topics);
    ui->ntopis->setText(st);

    QString sr = QString::number(num_replies);
    ui->nreplies->setText(sr);

    for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
    {
        ui->combocats->addItem(QString::fromUtf8(myPlatformFull.categories[i].getTitle().c_str()));
    }
    for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
    {
        ui->combocats_2->addItem(QString::fromUtf8(myPlatformFull.categories[i].getTitle().c_str()));
    }


    for(unsigned i = 0 ; i < myPlatformFull.users.size();i++)
    {
        ui->combousers->addItem(QString::fromUtf8(myPlatformFull.users[i].account.getUsername().c_str()));
    }


    //ui->nusers->setText((QString)num_users);
    //ui->ntopis->setText((QString)num_topics);
    //ui->nreplies->setText((QString)num_replies);
    //ui->ncats->setText((QString)num_cats);
    ui->cat_img->setPixmap(cat_img);
    ui->member_img->setPixmap(member_img);
    //ui->topic_img->setPixmap(topic_img);
    //ui->answer_img->setPixmap(answer_img);
}

controlPanel::~controlPanel()
{
    delete ui;
}

void controlPanel::on_pushButton_6_clicked()
{
    hide();
    homePageForAdmin hp;
    hp.setModal(true);
    hp.exec();
}

void controlPanel::on_pushButton_5_clicked()
{
    hide();
    loginform lgf;
    lgf.setModal(true);
    lgf.exec();
}









void controlPanel::on_pushButton_3_clicked()
{
    //getting the selected username
    qDebug()<<"here";
    QString qusername = ui->combousers->itemText(ui->combousers->currentIndex());
    qDebug() << qusername;
    qDebug()<<"here1";
    //getting correspondant user ban
    int x = -1;
    unsigned i = 0;
    while(i<myPlatformFull.users.size() && x == -1)
    {
        qDebug() << "here2";
        qDebug() << QString::fromStdString(myPlatformFull.users[i].account.getUsername());
        if(QString::fromStdString(myPlatformFull.users[i].account.getUsername()) == qusername)
        {
            qDebug() << "here3";
            x= myPlatformFull.users[i].account.getStatus();
        }
        i++;
    }
    if(x==1)
    {
        myPlatformFull.users[i-1].account.setStatus(0);
    }
    else
        myPlatformFull.users[i-1].account.setStatus(1);

}

void controlPanel::on_pushButton_4_clicked()
{

    QString qcatname = ui->combocats->itemText(ui->combocats->currentIndex());

    int x = -1;
    unsigned i = 0;
    while(i<myPlatformFull.categories.size() && x == -1)
    {
        if(QString::fromStdString(myPlatformFull.categories[i].getTitle()) == qcatname)
        {
            x= i;
        }
        i++;
    }
    if(!ui->edittitle->text().isEmpty() && !ui->edittitle->text().isEmpty())
    {
        myPlatformFull.categories[x].setTitle(ui->edittitle->text().toStdString());
        myPlatformFull.categories[x].setDescription(ui->edittitle->text().toStdString());
        QMessageBox::about(this,"Done","Details of cat changed.");
    }

    bool sth = ui->radioButton->isChecked();
    if(sth==true)
    {
        myPlatformFull.categories[x].setStatus(0);
        QMessageBox::about(this,"Done","Cat hidden successfully.");
    }
    bool sts = ui->radioButton_2->isChecked();
    if(sts==true)
    {
        myPlatformFull.categories[x].setStatus(1);
        QMessageBox::about(this,"Done","Cat set to visible successfully.");
    }

}

void controlPanel::on_pushButton_8_clicked()
{
    if(!ui->newdesc->text().isEmpty() && !ui->newtitle->text().isEmpty())
    {
        Category newcat;
        newcat.setDescription(ui->newdesc->text().toStdString());
        newcat.setID(myPlatformFull.categories.size()+1);
        newcat.setStatus(1);
        newcat.setTitle(ui->newtitle->text().toStdString());
        myPlatformFull.addCategory(newcat);
        QMessageBox::about(this,"Done","Cat added successfully.");
    }
            else
        {
        QMessageBox::about(this,"Error","Empty fields.");

        }

}

void controlPanel::on_pushButton_7_clicked()
{
    QString qcatname = ui->combocats_2->itemText(ui->combocats_2->currentIndex());
    int x = -1;
    unsigned i = 0;
    while(i<myPlatformFull.categories.size() && x == -1)
    {

        if(QString::fromStdString(myPlatformFull.categories[i].getTitle()) == qcatname)
        {
            x= i;
            myPlatformFull.categories.erase(myPlatformFull.categories.begin() + i);
        }
        i++;
    }


    QMessageBox::about(this,"Done","Cat deleted.");

}
