#include "homepageformember.h"
#include "ui_homepageformember.h"
#include "globalthings.h"
#include "displaycat.h"
#include <QScrollArea>
#include "createtopicpage.h"
#include "repliespage.h"
#include "showprofile.h"
#include "loginform.h"

homePageForMember::homePageForMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homePageForMember)
{
    ui->setupUi(this);
    ui->welcome->setText("Welcome back dear " + session);
    ui->tabWidget->removeTab(0);
    for(unsigned  i = 0 ; i < myPlatformFull.categories.size() ; i++)
    {
        QString catTitle = QString::fromUtf8(myPlatformFull.categories[i].getTitle().c_str());
        QString catDescription = QString::fromUtf8(myPlatformFull.categories[i].getDescription().c_str());
        displaycat* catWidget = new displaycat();
        catWidget->setThings(myPlatformFull.categories[i].topics);
        if(myPlatformFull.categories[i].getStatus() == 1)
        {
            ui->tabWidget->addTab(catWidget, catTitle);
            ui->tabWidget->setTabToolTip(i+1,catDescription);
        }

    }
    ui->tabWidget->removeTab(0);
}

homePageForMember::~homePageForMember()
{
    delete ui;
}


//create
void homePageForMember::on_pushButton_clicked()
{
    hide();
    createTopicPage ctpic;
    ctpic.setModal(true);
    ctpic.exec();
}

//inbox
void homePageForMember::on_pushButton_3_clicked()
{
    hide();
    repliespage inbox;
    inbox.setModal(true);
    inbox.exec();

}
//profile
void homePageForMember::on_pushButton_2_clicked()
{
    hide();
    showprofile sp;
    sp.setModal(true);
    sp.exec();
}

void homePageForMember::on_pushButton_4_clicked()
{
    //code to save to db
    hide();
    loginform lf;
    lf.setModal(true);
    lf.exec();

}
