#include "manageanswers.h"
#include "ui_manageanswers.h"

manageAnswers::manageAnswers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageAnswers)
{
    ui->setupUi(this);
}

manageAnswers::~manageAnswers()
{
    delete ui;
}
