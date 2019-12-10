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
void buttonPressed_moreHigh();
void buttonReleased_moreHigh();
void buttonPressed_low();
void buttonReleased_low();
void buttonPressed_moreLow();
void buttonReleased_moreLow();
void doIncrement();
void doDecrement();
void doMoreIncrement();
void doMoreDecrement();

private:
    Ui::ButtonInc *ui;
    QTimer *timer_high, *timer_low;
    int timerTimeout;
    int number;
};
#endif // BUTTONINC_H
