#include "createtopicpage.h"
#include "ui_createtopicpage.h"
#include "globalthings.h"
#include "homepageforadmin.h"
#include "controlpanel.h"
#include <QMessageBox>
#include <QDebug>
#include "homepageformember.h"

createTopicPage::createTopicPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTopicPage)
{
    ui->setupUi(this);

    for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
    {
        ui->catsList->addItem(QString::fromUtf8(myPlatformFull.categories[i].getTitle().c_str()));
    }
}

createTopicPage::~createTopicPage()
{
    delete ui;
}

void createTopicPage::on_homepagebutton_clicked()
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

void createTopicPage::on_cpbutton_clicked()
{
    hide();
    controlPanel cp;
    cp.setModal(true);
    cp.exec();
}

void createTopicPage::on_Submit_clicked()
{
    QString title = ui->topicTitle->text();
    QString body = ui->topicBody->toPlainText();
    QString cattitle = ui->catsList->currentText();
    if(!title.isEmpty() && !body.isEmpty() && !cattitle.isEmpty())
    {
        int counter = 0;
        for(unsigned b = 0 ; b < myPlatformFull.categories.size();b++)
        {
            counter += myPlatformFull.categories[b].topics.size();

        }

        for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
        {
            if(cattitle == QString::fromStdString(myPlatformFull.categories[i].getTitle()))
            {
                Topic temptopic;
                temptopic.setCatID(myPlatformFull.categories[i].getID());
                temptopic.setAuthor(currentUser.account.getUsername());
                temptopic.setBody(body.toStdString());
                QString sCurrentDate = currenDate.toString("dd-MM-yyyy");
                temptopic.setDate(sCurrentDate.toStdString());
                temptopic.setID(counter+1);
                //temptopic.setID(myPlatformFull.categories[i].topics.size()+2);
                if(currentUser.getRole() == 1)
                    temptopic.setStatus(1);
                else
                    temptopic.setStatus(0);

                temptopic.setTitle(title.toStdString());
                myPlatformFull.categories[i].addTopic(temptopic);
                if(currentUser.getRole() == 1)
                    QMessageBox::about(this,"Done","The topic was added succesfully to the board. ");
                else
                    QMessageBox::about(this,"Done","The topic was added succesfully to the board.It won't appear until a moderator checks it. Thanks ");
            }
        }
    }
    else
    {
        QMessageBox::about(this,"Error","Empty fields not authorized.");
    }

}
