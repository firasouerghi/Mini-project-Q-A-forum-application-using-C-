#ifndef EDITTOPICWINDOW_H
#define EDITTOPICWINDOW_H

#include <QDialog>

namespace Ui {
class editTopicWindow;
}

class editTopicWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editTopicWindow(QWidget *parent = 0);
    ~editTopicWindow();

    Ui::editTopicWindow *ui;
private slots:
    void on_save_clicked();
    void on_Return_2_clicked();
};

#endif // EDITTOPICWINDOW_H
