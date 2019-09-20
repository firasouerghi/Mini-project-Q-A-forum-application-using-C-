#include "homepageforadmin.h"
#include "ui_homepageforadmin.h"
#include "controlpanel.h"
#include "globalthings.h"
#include "displaycat.h"
#include <QScrollArea>
#include "createtopicpage.h"
#include "repliespage.h"
#include "showprofile.h"
#include "loginform.h"

homePageForAdmin::homePageForAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homePageForAdmin)
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
        ui->tabWidget->addTab(catWidget, catTitle);
        ui->tabWidget->setTabToolTip(i+1,catDescription);
    }
    ui->tabWidget->removeTab(0);
}

homePageForAdmin::~homePageForAdmin()
{
    delete ui;
}



void homePageForAdmin::on_createtopicbutton_clicked()
{
    hide();
    createTopicPage ctpic;
    ctpic.setModal(true);
    ctpic.exec();
}

void homePageForAdmin::on_cpbutton_clicked()
{
    hide();
    controlPanel controlpanel;
    controlpanel.setModal(true);
    controlpanel.exec();
}

void homePageForAdmin::on_inboxbutton_clicked()
{
    hide();
    repliespage inbox;
    inbox.setModal(true);
    inbox.exec();

}

void homePageForAdmin::on_profilebutton_clicked()
{
    hide();
    showprofile sp;
    sp.setModal(true);
    sp.exec();

}

void homePageForAdmin::on_pushButton_clicked()
{
    //code to save to db
    hide();
    loginform lf;
    lf.setModal(true);
    lf.exec();
}
