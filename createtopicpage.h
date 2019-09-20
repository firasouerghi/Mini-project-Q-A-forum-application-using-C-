#ifndef CREATETOPICPAGE_H
#define CREATETOPICPAGE_H

#include <QDialog>

namespace Ui {
class createTopicPage;
}

class createTopicPage : public QDialog
{
    Q_OBJECT

public:
    explicit createTopicPage(QWidget *parent = 0);
    ~createTopicPage();

private slots:
    void on_homepagebutton_clicked();

    void on_cpbutton_clicked();

    void on_Submit_clicked();

private:
    Ui::createTopicPage *ui;
};

#endif // CREATETOPICPAGE_H
