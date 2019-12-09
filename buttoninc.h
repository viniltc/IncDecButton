#ifndef BUTTONINC_H
#define BUTTONINC_H

#include <QMainWindow>
class QTimer;

QT_BEGIN_NAMESPACE
namespace Ui { class ButtonInc; }
QT_END_NAMESPACE

class ButtonInc : public QMainWindow
{
    Q_OBJECT

public:
    ButtonInc(QWidget *parent = nullptr);
    ~ButtonInc();

protected slots:
void buttonPressed_high();
void buttonReleased_high();
void buttonPressed_low();
void buttonReleased_low();
void doIncrement();
void doDecrement();

private:
    Ui::ButtonInc *ui;
    QTimer *timer_high, *timer_low;
    int timerTimeout;
    int number;
};
#endif // BUTTONINC_H
