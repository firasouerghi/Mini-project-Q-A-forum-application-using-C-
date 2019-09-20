#ifndef LOGINFORM_H
#define LOGINFORM_H
#include <QDialog>


namespace Ui {
class loginform;
}

class loginform : public QDialog
{
    Q_OBJECT

public:
    explicit loginform(QWidget *parent = 0);
    ~loginform();

private slots:
    void on_homeButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::loginform *ui;


};

#endif // LOGINFORM_H
