#include "managecats.h"
#include "ui_managecats.h"

manageCats::manageCats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageCats)
{
    ui->setupUi(this);
}

manageCats::~manageCats()
{
    delete ui;
}
