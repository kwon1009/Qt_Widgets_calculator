#include "widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(210, 310);
    cal = new Calculator(0);

    // display
    m_display = new QLineEdit("", this);
    m_display->setGeometry(10, 10, 190, 40);

    // number buttons
    for(int i=0; i<10; i++) {
        QString m_str = QString("%1").arg(i);
        m_btn_nums[i] = new QPushButton(m_str, this);
    }
    m_btn_nums[1]->setGeometry(10, 110, 40, 40);
    m_btn_nums[2]->setGeometry(60, 110, 40, 40);
    m_btn_nums[3]->setGeometry(110, 110, 40, 40);
    m_btn_nums[4]->setGeometry(10, 160, 40, 40);
    m_btn_nums[5]->setGeometry(60, 160, 40, 40);
    m_btn_nums[6]->setGeometry(110, 160, 40, 40);
    m_btn_nums[7]->setGeometry(10, 210, 40, 40);
    m_btn_nums[8]->setGeometry(60, 210, 40, 40);
    m_btn_nums[9]->setGeometry(110, 210, 40, 40);
    m_btn_nums[0]->setGeometry(10, 260, 90, 40);

    m_btn_dot = new QPushButton(".", this);
    m_btn_dot->setGeometry(110, 260, 40, 40);

    connect(m_btn_nums[0], SIGNAL(pressed()), this, SLOT(slot_input_0()));
    connect(m_btn_nums[1], SIGNAL(pressed()), this, SLOT(slot_input_1()));
    connect(m_btn_nums[2], SIGNAL(pressed()), this, SLOT(slot_input_2()));
    connect(m_btn_nums[3], SIGNAL(pressed()), this, SLOT(slot_input_3()));
    connect(m_btn_nums[4], SIGNAL(pressed()), this, SLOT(slot_input_4()));
    connect(m_btn_nums[5], SIGNAL(pressed()), this, SLOT(slot_input_5()));
    connect(m_btn_nums[6], SIGNAL(pressed()), this, SLOT(slot_input_6()));
    connect(m_btn_nums[7], SIGNAL(pressed()), this, SLOT(slot_input_7()));
    connect(m_btn_nums[8], SIGNAL(pressed()), this, SLOT(slot_input_8()));
    connect(m_btn_nums[9], SIGNAL(pressed()), this, SLOT(slot_input_9()));
    connect(m_btn_dot, SIGNAL(pressed()), this, SLOT(slot_input_dot()));


    // operators
    m_btn_opers[1] = new QPushButton("/", this);
    m_btn_opers[1]->setGeometry(110, 60, 40, 40);
    m_btn_opers[2] = new QPushButton("*", this);
    m_btn_opers[2]->setGeometry(160, 110, 40, 40);
    m_btn_opers[3] = new QPushButton("+", this);
    m_btn_opers[3]->setGeometry(160, 160, 40, 40);
    m_btn_opers[4] = new QPushButton("-", this);
    m_btn_opers[4]->setGeometry(160, 210, 40, 40);
    m_btn_opers[0] = new QPushButton("=", this);
    m_btn_opers[0]->setGeometry(160, 260, 40, 40);

    connect(m_btn_opers[1], SIGNAL(pressed()), this, SLOT(slot_input_div()));
    connect(m_btn_opers[2], SIGNAL(pressed()), this, SLOT(slot_input_mul()));
    connect(m_btn_opers[3], SIGNAL(pressed()), this, SLOT(slot_input_add()));
    connect(m_btn_opers[4], SIGNAL(pressed()), this, SLOT(slot_input_sub()));
    connect(m_btn_opers[0], SIGNAL(pressed()), this, SLOT(slot_input_equal()));

    // functions
    m_btn_ac = new QPushButton("AC", this);
    m_btn_ac->setGeometry(10, 60, 40, 40);
    m_btn_back = new QPushButton("Back", this);
    m_btn_back->setGeometry(160, 60, 40, 40);
    m_btn_history = new QPushButton("H", this);
    m_btn_history->setGeometry(60, 60, 40, 40);

    connect(m_btn_ac, SIGNAL(pressed()), this, SLOT(slot_clear()));
    connect(m_btn_back, SIGNAL(pressed()), this, SLOT(slot_back()));
    connect(m_btn_history, SIGNAL(pressed()), this, SLOT(slot_history()));

}

void Widget::display(QString val)
{
    QString str = m_display->text() + val;
    m_display->setText(str);
}

void Widget::display_error(errors err)
{
    QString str = cal->getErrorMessage(err);
    m_display->setText(str);
}

void Widget::slot_input_0()
{
    display("0");
}
void Widget::slot_input_1()
{
    display("1");
}
void Widget::slot_input_2()
{
    display("2");
}
void Widget::slot_input_3()
{
    display("3");
}
void Widget::slot_input_4()
{
    display("4");
}
void Widget::slot_input_5()
{
    display("5");
}
void Widget::slot_input_6()
{
    display("6");
}
void Widget::slot_input_7()
{
    display("7");
}
void Widget::slot_input_8()
{
    display("8");
}
void Widget::slot_input_9()
{
    display("9");
}

void Widget::slot_input_dot()
{
    display(".");
}

void Widget::slot_input_add()
{
    display("+");
}
void Widget::slot_input_sub()
{
    display("-");
}
void Widget::slot_input_mul()
{
    display("*");
}
void Widget::slot_input_div()
{
    display("/");
}

void Widget::slot_input_equal()
{
    QString calLine = m_display->text();

    try {
        double result = cal->calculate(calLine);
        m_display->setText(QString("%1").arg(result));
    }  catch (errors err) {
        display_error(err);
    }
}


void Widget::slot_clear()
{
    m_display->setText("");
}

void Widget::slot_back()
{
    QString str = m_display->text();
    str.chop(1);
    m_display->setText(str);
}

void Widget::slot_history()
{
    QString str = cal->getLastCal();
    m_display->setText(str);
}

Widget::~Widget()
{
}

