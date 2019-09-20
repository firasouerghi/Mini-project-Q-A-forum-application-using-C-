#include "displaycat.h"
#include "ui_displaycat.h"
#include "QPushButton"
#include "viewtopicwindow.h"
#include "globalthings.h"
#include "QDebug"
#include "qsignalmapper.h"
#include "homepageforadmin.h"
#include <QMainWindow>
displaycat::displaycat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displaycat)
{
    ui->setupUi(this);


}

displaycat::~displaycat()
{
    delete ui;
}

void displaycat::viewTopic(int a)
{

    IDTopic = a;
    this->parentWidget()->parentWidget()->parentWidget()->hide();
    ViewTopicWindow *topicpage = new ViewTopicWindow();
    topicpage->exec();
}



void displaycat::setThings(vector<Topic> t)
{

    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    for(unsigned i = 0 ; i < t.size() ; i++)
    {
        if(rolesession == 1)
        {
            QLabel *topictitlelabel = new QLabel();
            topictitlelabel->setText(QString::fromUtf8(t[i].getTitle().c_str()));
            topictitlelabel->setStyleSheet("padding:10px 10px 10px 10px; background-color: #7f8c8d; font-weight: bold; color: #ecf0f1");
            topictitlelabel->setFixedWidth(550);

            QPushButton *pushButtonViewTopic = new QPushButton();
            int menu_x_pos = topictitlelabel->pos().x();
            int menu_y_pos = topictitlelabel->pos().y();
            pushButtonViewTopic->setGeometry(menu_x_pos+120, menu_y_pos,10,20);
            pushButtonViewTopic->setText("View topic");
            pushButtonViewTopic->setStyleSheet("padding:10px 10px 10px 10px;background-color: #3498db");
            pushButtonViewTopic->setObjectName((QString)t[i].getID());
            ui->formLayout->insertRow(i,topictitlelabel,pushButtonViewTopic);
            connect (pushButtonViewTopic, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
            signalMapper -> setMapping (pushButtonViewTopic, t[i].getID()) ;

        }
        else
        {
            if(t[i].getStatus() !=0)
            {
                QLabel *topictitlelabel = new QLabel();
                topictitlelabel->setText(QString::fromUtf8(t[i].getTitle().c_str()));
                topictitlelabel->setStyleSheet("padding:10px 10px 10px 10px; background-color: #7f8c8d; font-weight: bold; color: #ecf0f1");
                topictitlelabel->setFixedWidth(550);
                if(rolesession == -2 )
                    topictitlelabel->setFixedWidth(680);
                QPushButton *pushButtonViewTopic = new QPushButton();
                int menu_x_pos = topictitlelabel->pos().x();
                int menu_y_pos = topictitlelabel->pos().y();
                pushButtonViewTopic->setGeometry(menu_x_pos+120, menu_y_pos,10,20);
                pushButtonViewTopic->setText("View topic");
                pushButtonViewTopic->setStyleSheet("padding:10px 10px 10px 10px;background-color: #3498db");
                pushButtonViewTopic->setObjectName((QString)t[i].getID());
                ui->formLayout->insertRow(i,topictitlelabel,pushButtonViewTopic);
                connect (pushButtonViewTopic, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
                signalMapper -> setMapping (pushButtonViewTopic, t[i].getID()) ;
                if(rolesession == -2)
                    pushButtonViewTopic->setVisible(false);

            }

        }


    }
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(viewTopic(int))) ;
}




