#ifndef HOMEPAGEFORMEMBER_H
#define HOMEPAGEFORMEMBER_H

#include <QDialog>

namespace Ui {
class homePageForMember;
}

class homePageForMember : public QDialog
{
    Q_OBJECT

public:
    explicit homePageForMember(QWidget *parent = 0);
    ~homePageForMember();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::homePageForMember *ui;
};

#endif // HOMEPAGEFORMEMBER_H
