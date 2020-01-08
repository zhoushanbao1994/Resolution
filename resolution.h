#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <QWidget>

namespace Ui {
class Resolution;
}

class Resolution : public QWidget
{
    Q_OBJECT

public:
    explicit Resolution(QWidget *parent = nullptr);
    ~Resolution();

private:
    Ui::Resolution *ui;
};

#endif // RESOLUTION_H
