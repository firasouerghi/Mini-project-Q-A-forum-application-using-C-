#include "forumindex.h"
#include "ui_forumindex.h"
#include "signupform.h"
#include "globalthings.h"
#include "displaycat.h"
#include "globalthings.h"

forumindex::forumindex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forumindex)
{
    ui->setupUi(this);
    rolesession = -2;
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

forumindex::~forumindex()
{
    delete ui;
}

void forumindex::on_pushButton_clicked()
{
    hide();
    signupform sgnp;
    sgnp.setModal(true);
    sgnp.exec();

}
