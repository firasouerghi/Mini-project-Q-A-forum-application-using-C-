#ifndef WRITEPM_H
#define WRITEPM_H

#include <QDialog>

namespace Ui {
class writepm;
}

class writepm : public QDialog
{
    Q_OBJECT

public:
    explicit writepm(QWidget *parent = 0);
    ~writepm();

private slots:
    void on_homepagebutton_clicked();

    void on_Submit_clicked();

private:
    Ui::writepm *ui;
};

#endif // WRITEPM_H
