#include "addreplypage.h"
#include "ui_addreplypage.h"
#include "Reply.h"
#include "globalthings.h"
#include <QDebug>
#include <QMessageBox>
#include <homepageforadmin.h>
#include "homepageformember.h"

addReplyPage::addReplyPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addReplyPage)
{
    ui->setupUi(this);
}

addReplyPage::~addReplyPage()
{
    delete ui;
}

void addReplyPage::on_Submit_clicked()
{
    QString bodyReply = ui->replyBody->toPlainText();

    if(!bodyReply.isEmpty())
    {
        Reply newReply;

        newReply.setAuthor(currentUser.account.getUsername());
        newReply.setBody(bodyReply.toStdString());
        newReply.setDate(currenDate.toString("dd-MM-yyyy").toStdString());


        if(currentUser.getRole() == 1)
            newReply.setStatus(1);
        else
            newReply.setStatus(0);
        newReply.setTopicID(IDTopic);

        int hostCatID = 0;
        for(unsigned i = 0 ; i < myPlatformFull.categories.size();i++)
        {
            for(unsigned j = 0; j < myPlatformFull.categories[i].topics.size();j++)
            {
                if(myPlatformFull.categories[i].topics[j].getID() == IDTopic)
                    hostCatID = myPlatformFull.categories[i].getID();
            }
        }
        int counter = 0 ;
        for(unsigned g = 0 ; g <myPlatformFull.categories.size();g++)
        {
            for(unsigned f = 0; f < myPlatformFull.categories[g].topics.size();f++)
            {
                counter += myPlatformFull.categories[g].topics[f].replies.size();
            }
        }
        newReply.setID(counter+1);


        for(unsigned m = 0 ; m < myPlatformFull.categories[hostCatID-1].topics.size(); m++)
        {
            if(myPlatformFull.categories[hostCatID-1].topics[m].getID() == IDTopic)
            {
                myPlatformFull.categories[hostCatID-1].topics[m].addReply(newReply);
                if(currentUser.getRole() == 1)
                {
                    QMessageBox::about(this,"Done","Reply added successfully");
                }
                else
                    QMessageBox::about(this,"Done","Reply added, it will appear after admin control.");
            }
        }

    }
    else
    {
        QMessageBox::about(this,"Empty answer", "Don't leave the text field empty.");
    }


}


void addReplyPage::on_Return_clicked()
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
