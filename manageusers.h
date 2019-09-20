#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <QDialog>

namespace Ui {
class manageUsers;
}

class manageUsers : public QDialog
{
    Q_OBJECT

public:
    explicit manageUsers(QWidget *parent = 0);
    ~manageUsers();

private:
    Ui::manageUsers *ui;
};

#endif // MANAGEUSERS_H
