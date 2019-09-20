#ifndef DISPLAYCAT_H
#define DISPLAYCAT_H

#include <QWidget>
#include <vector>
#include "Topic.h"
using namespace std ;
namespace Ui {
class displaycat;
}

class displaycat : public QWidget
{
    Q_OBJECT

public slots:
        void viewTopic(int a);
public:
    explicit displaycat(QWidget *parent = 0);
    ~displaycat();
    void setThings(vector<Topic> t);



private:
    Ui::displaycat *ui;
};

#endif // DISPLAYCAT_H
