#ifndef FORUMINDEX_H
#define FORUMINDEX_H

#include <QDialog>

namespace Ui {
class forumindex;
}

class forumindex : public QDialog
{
    Q_OBJECT

public:
    explicit forumindex(QWidget *parent = 0);
    ~forumindex();

private slots:
    void on_pushButton_clicked();

private:
    Ui::forumindex *ui;
};

#endif // FORUMINDEX_H
