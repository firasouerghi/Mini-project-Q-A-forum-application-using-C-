#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>



namespace Ui {
class signupform;
}

class signupform : public QDialog
{
    Q_OBJECT

public:
    explicit signupform(QWidget *parent = 0);
    ~signupform();

private slots:
    void on_backHome_clicked();

    void on_signupButton_clicked();

private:
    Ui::signupform *ui;
};

#endif // SIGNUPFORM_H
