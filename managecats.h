#ifndef MANAGECATS_H
#define MANAGECATS_H

#include <QDialog>

namespace Ui {
class manageCats;
}

class manageCats : public QDialog
{
    Q_OBJECT

public:
    explicit manageCats(QWidget *parent = 0);
    ~manageCats();

private:
    Ui::manageCats *ui;
};

#endif // MANAGECATS_H
