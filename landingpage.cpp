#include "landingpage.h"
#include "ui_landingpage.h"
#include <QPixmap>
#include "loginform.h"
#include "signupform.h"
#include "forumindex.h"
#include "dbqueries.h"
#include "globalthings.h"

LandingPage::LandingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LandingPage)
{
    ui->setupUi(this);

    //Retrieving images for landing page
    QPixmap guest_img("img/login-guest.png");
    QPixmap member_img("img/login-member.png");
    QPixmap signup_img("img/signup.png");
    ui->guest_img->setPixmap(guest_img);
    ui->member_img->setPixmap(member_img);
    ui->signup_img->setPixmap(signup_img);
    if(alyncibi == 0)
    {
        initCatsList();
        initTopicsList();
        initRepliesList();
        initUsersList();
        initPMsList();
    }


}

LandingPage::~LandingPage()
{
    delete ui;
}


void LandingPage::on_LoginAsMemberButton_clicked()
{
    hide();
    loginform logform;
    logform.setModal(true);
    logform.exec();
}

void LandingPage::on_SignupButton_clicked()
{
    hide();
    signupform sgnupform;
    sgnupform.setModal(true);
    sgnupform.exec();
}

void LandingPage::on_LoginAsGuestButton_clicked()
{
    hide();
    forumindex indexpage;
    indexpage.setModal(true);
    indexpage.exec();
}
