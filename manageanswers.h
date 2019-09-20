#ifndef MANAGEANSWERS_H
#define MANAGEANSWERS_H

#include <QDialog>

namespace Ui {
class manageAnswers;
}

class manageAnswers : public QDialog
{
    Q_OBJECT

public:
    explicit manageAnswers(QWidget *parent = 0);
    ~manageAnswers();

private:
    Ui::manageAnswers *ui;
};

#endif // MANAGEANSWERS_H
