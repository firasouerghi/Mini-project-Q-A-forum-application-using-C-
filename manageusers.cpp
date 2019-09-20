#include "manageusers.h"

manageUsers::manageUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageUsers)
{
    ui->setupUi(this);
}

manageUsers::~manageUsers()
{
    delete ui;
}
