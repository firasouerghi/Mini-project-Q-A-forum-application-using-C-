#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QDialog>

namespace Ui {
class controlPanel;
}

class controlPanel : public QDialog
{
    Q_OBJECT

public:
    explicit controlPanel(QWidget *parent = 0);
    ~controlPanel();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();


    void on_combousers_editTextChanged(const QString &arg1);

    void on_combousers_currentIndexChanged(int index);

    void on_combousers_currentTextChanged(const QString &arg1);

    void on_promote_or_not_clicked();

    void on_ban_or_activate_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::controlPanel *ui;
};

#endif // CONTROLPANEL_H
