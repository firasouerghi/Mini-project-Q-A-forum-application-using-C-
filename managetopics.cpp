#include "managetopics.h"
#include "ui_managetopics.h"

manageTopics::manageTopics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageTopics)
{
    ui->setupUi(this);
}

manageTopics::~manageTopics()
{
    delete ui;
}
