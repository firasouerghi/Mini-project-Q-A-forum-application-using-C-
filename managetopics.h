#ifndef MANAGETOPICS_H
#define MANAGETOPICS_H

#include <QDialog>

namespace Ui {
class manageTopics;
}

class manageTopics : public QDialog
{
    Q_OBJECT

public:
    explicit manageTopics(QWidget *parent = 0);
    ~manageTopics();

private:
    Ui::manageTopics *ui;
};

#endif // MANAGETOPICS_H
