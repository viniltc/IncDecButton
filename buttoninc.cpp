#include "buttoninc.h"
#include "ui_buttoninc.h"
#include <QTimer>

ButtonInc::ButtonInc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ButtonInc)
{
    ui->setupUi(this);

    number = 0;
    timerTimeout = 0;
    timer_high = new QTimer(this);
    timer_low = new QTimer(this);
    ui->label->setAlignment(Qt::AlignCenter);


    connect(timer_high, &QTimer::timeout, this, &ButtonInc::doIncrement);
    connect(timer_low, &QTimer::timeout, this, &ButtonInc::doDecrement);
    connect(timer_high, &QTimer::timeout, this, &ButtonInc::doMoreIncrement);
    connect(timer_low, &QTimer::timeout, this, &ButtonInc::doMoreDecrement);


    connect(ui->pushButton_high, &QPushButton::pressed, this, &ButtonInc::buttonPressed_high);
    connect(ui->pushButton_high,  &QPushButton::released, this, &ButtonInc::buttonReleased_high);
    connect(ui->pushButton_veryHigh, &QPushButton::pressed, this, &ButtonInc::buttonPressed_veryHigh);
    connect(ui->pushButton_veryHigh,  &QPushButton::released, this, &ButtonInc::buttonReleased_veryHigh);

    connect(ui->pushButton_low, &QPushButton::pressed, this, &ButtonInc::buttonPressed_low);
    connect(ui->pushButton_low, &QPushButton::released, this, &ButtonInc::buttonReleased_low);
    connect(ui->pushButton_veryLow, &QPushButton::pressed, this, &ButtonInc::buttonPressed_veryLow);
    connect(ui->pushButton_veryLow, &QPushButton::released, this, &ButtonInc::buttonReleased_veryLow);



}

ButtonInc::~ButtonInc()
{
    delete ui;
}

void ButtonInc::buttonPressed_high()
{
timerTimeout = 5000;
doIncrement();
}

void ButtonInc::buttonReleased_high()
{
timer_high->stop();
}

void ButtonInc::buttonPressed_veryHigh()
{
timerTimeout = 5000;
doMoreIncrement();
}

void ButtonInc::buttonReleased_veryHigh()
{
timer_high->stop();
}

void ButtonInc::buttonPressed_low()
{
timerTimeout = 5000;
doDecrement();
}

void ButtonInc::buttonReleased_low()
{
timer_low->stop();
}
void ButtonInc::buttonPressed_veryLow()
{
timerTimeout = 5000;
doMoreDecrement();
}

void ButtonInc::buttonReleased_veryLow()
{
timer_low->stop();
}

void ButtonInc::doIncrement()
{
++number;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_high->start(timerTimeout);
}

void ButtonInc::doDecrement()

{
number--;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_low->start(timerTimeout);
}

void ButtonInc::doMoreIncrement()
{
number=number+5;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_high->start(timerTimeout);
}

void ButtonInc::doMoreDecrement()

{
number=number-5;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_low->start(timerTimeout);
}

