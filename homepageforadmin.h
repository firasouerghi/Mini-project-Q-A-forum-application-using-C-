#ifndef HOMEPAGEFORADMIN_H
#define HOMEPAGEFORADMIN_H

#include <QDialog>
#include "globalthings.h"

namespace Ui {
class homePageForAdmin;
}

class homePageForAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit homePageForAdmin(QWidget *parent = 0);
    ~homePageForAdmin();

private slots:

    void on_createtopicbutton_clicked();

    void on_cpbutton_clicked();

    void on_inboxbutton_clicked();

    void on_profilebutton_clicked();

    void on_pushButton_clicked();

private:
    Ui::homePageForAdmin *ui;
};

#endif // HOMEPAGEFORADMIN_H
