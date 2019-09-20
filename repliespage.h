#ifndef REPLIESPAGE_H
#define REPLIESPAGE_H

#include <QDialog>

namespace Ui {
class repliespage;
}

class repliespage : public QDialog
{
    Q_OBJECT

public:
    explicit repliespage(QWidget *parent = 0);
    ~repliespage();


private slots:
    void dothing(int a);
    void on_homebutton_clicked();

    void on_createbutton_clicked();

private:
    Ui::repliespage *ui;
};

#endif // REPLIESPAGE_H
