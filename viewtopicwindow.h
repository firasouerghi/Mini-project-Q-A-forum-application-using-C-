#ifndef VIEWTOPICWINDOW_H
#define VIEWTOPICWINDOW_H

#include <QDialog>

namespace Ui {
class ViewTopicWindow;
}

class ViewTopicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTopicWindow(QWidget *parent = 0);
    ~ViewTopicWindow();

private slots:
    void on_pushButton_clicked();

    void on_addReplyButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_hidebutton_clicked();
    void ddo(int a);

private:
    Ui::ViewTopicWindow *ui;
};

#endif // VIEWTOPICWINDOW_H
