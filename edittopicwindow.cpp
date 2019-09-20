#include "edittopicwindow.h"
#include "ui_edittopicwindow.h"
#include "globalthings.h"
#include "homepageforadmin.h"
#include <QMessageBox>
#include "homepageformember.h"

editTopicWindow::editTopicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editTopicWindow)
{
    ui->setupUi(this);


}

editTopicWindow::~editTopicWindow()
{
    delete ui;
}

void editTopicWindow::on_save_clicked()
{
    if(!ui->replyBody_2->toPlainText().isEmpty())
    {
        QString topic_body = ui->replyBody_2->toPlainText();

        for(unsigned i = 0; i<myPlatformFull.categories.size();i++)
        {
            for(unsigned j = 0 ; j < myPlatformFull.categories[i].topics.size(); j++ )
            {
                if(myPlatformFull.categories[i].topics[j].getID() == IDTopic)
                {
                    myPlatformFull.categories[i].topics[j].setBody(topic_body.toStdString());
                    hide();
                    homePageForAdmin *hp = new homePageForAdmin;
                    hp->exec();
                }
            }
        }
    }
    else
    {
        QMessageBox::about(this,"Sorry","Topic body can't be empty.");
    }
}

void editTopicWindow::on_Return_2_clicked()
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
