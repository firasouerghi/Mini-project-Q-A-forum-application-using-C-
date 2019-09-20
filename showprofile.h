#ifndef SHOWPROFILE_H
#define SHOWPROFILE_H

#include <QDialog>

namespace Ui {
class showprofile;
}

class showprofile : public QDialog
{
    Q_OBJECT

public:
    explicit showprofile(QWidget *parent = 0);
    ~showprofile();

private slots:
    void on_inboxbutton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::showprofile *ui;
};

#endif // SHOWPROFILE_H
