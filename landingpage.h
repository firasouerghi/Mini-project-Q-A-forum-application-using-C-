#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QMainWindow>


namespace Ui {
class LandingPage;
}

class LandingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LandingPage(QWidget *parent = 0);
    ~LandingPage();

private slots:
    void on_LoginAsMemberButton_clicked();
    void on_SignupButton_clicked();
    void on_LoginAsGuestButton_clicked();

private:
    Ui::LandingPage *ui;
};

#endif // LANDINGPAGE_H
