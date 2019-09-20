#ifndef ADDREPLYPAGE_H
#define ADDREPLYPAGE_H

#include <QDialog>

namespace Ui {
class addReplyPage;
}

class addReplyPage : public QDialog
{
    Q_OBJECT

public:
    explicit addReplyPage(QWidget *parent = 0);
    ~addReplyPage();

private slots:
    void on_Submit_clicked();


    void on_Return_clicked();

private:
    Ui::addReplyPage *ui;
};

#endif // ADDREPLYPAGE_H
