#include "widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(210, 310);
    m_result = 0;

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
    m_btn_opers[0] = new QPushButton("%", this);
    m_btn_opers[0]->setGeometry(60, 60, 40, 40);
    m_btn_opers[1] = new QPushButton("/", this);
    m_btn_opers[1]->setGeometry(110, 60, 40, 40);
    m_btn_opers[2] = new QPushButton("*", this);
    m_btn_opers[2]->setGeometry(160, 110, 40, 40);
    m_btn_opers[3] = new QPushButton("+", this);
    m_btn_opers[3]->setGeometry(160, 160, 40, 40);
    m_btn_opers[4] = new QPushButton("-", this);
    m_btn_opers[4]->setGeometry(160, 210, 40, 40);
    m_btn_opers[5] = new QPushButton("=", this);
    m_btn_opers[5]->setGeometry(160, 260, 40, 40);

    connect(m_btn_opers[0], SIGNAL(pressed()), this, SLOT(slot_input_rem()));
    connect(m_btn_opers[1], SIGNAL(pressed()), this, SLOT(slot_input_div()));
    connect(m_btn_opers[2], SIGNAL(pressed()), this, SLOT(slot_input_mul()));
    connect(m_btn_opers[3], SIGNAL(pressed()), this, SLOT(slot_input_add()));
    connect(m_btn_opers[4], SIGNAL(pressed()), this, SLOT(slot_input_sub()));
    connect(m_btn_opers[5], SIGNAL(pressed()), this, SLOT(slot_input_equal()));

    // functions
    m_btn_ac = new QPushButton("AC", this);
    m_btn_ac->setGeometry(10, 60, 40, 40);
    m_btn_back = new QPushButton("Back", this);
    m_btn_back->setGeometry(160, 60, 40, 40);

    connect(m_btn_ac, SIGNAL(pressed()), this, SLOT(slot_clear()));
    connect(m_btn_back, SIGNAL(pressed()), this, SLOT(slot_back()));

}

void Widget::slot_input_0()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(0);
    qDebug() << m_display->text();
    m_display->setText(str);
}
void Widget::slot_input_1()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(1);
    m_display->setText(str);
}
void Widget::slot_input_2()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(2);
    m_display->setText(str);
}
void Widget::slot_input_3()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(3);
    m_display->setText(str);
}
void Widget::slot_input_4()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(4);
    m_display->setText(str);
}
void Widget::slot_input_5()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(5);
    m_display->setText(str);
}
void Widget::slot_input_6()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(6);
    m_display->setText(str);
}
void Widget::slot_input_7()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(7);
    m_display->setText(str);
}
void Widget::slot_input_8()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(8);
    m_display->setText(str);
}
void Widget::slot_input_9()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(9);
    m_display->setText(str);
}

void Widget::slot_input_dot()
{
    QString str = QString("%1%2").arg(m_display->text()).arg(".");
    m_display->setText(str);
}


void Widget::slot_input_add()
{
    QString str = QString("%1%2").arg(m_display->text()).arg("+");
    m_display->setText(str);
}

void Widget::slot_input_sub()
{
    QString str = QString("%1%2").arg(m_display->text()).arg("-");
    m_display->setText(str);
}

void Widget::slot_input_mul()
{
    QString str = QString("%1%2").arg(m_display->text()).arg("*");
    m_display->setText(str);
}

void Widget::slot_input_div()
{
    QString str = QString("%1%2").arg(m_display->text()).arg("/");
    m_display->setText(str);
}

void Widget::slot_input_rem()
{
    QString str = QString("%1%2").arg(m_display->text()).arg("%");
    m_display->setText(str);
}

void Widget::slot_input_equal()
{
    QString calLine = m_display->text();
    qDebug() << "slot_input_equal() : " << calLine;
    calculate(calLine);
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


double Widget::calculate(QString calLine) {
    int i;
    int s;
    QVector<double> nums;
    QVector<QChar> opers;
    nums.clear();
    opers.clear();

    s = 0;
    for(i=0; i<calLine.length(); i++) {
        // 알파벳을 입력한 경우
        if(calLine[i].isLetter()) {
            return 0;
        }

        // 숫자가 아닌 경우
        if(!calLine[i].isNumber()) {
            if(calLine[i] != '.') {
                opers.push_back(calLine[i]);
                double num = calLine.mid(s, (i-s)).toDouble();
                s = i + 1;
                nums.push_back(num);
            }
        }
    }
    if(s < i) {
        double num = calLine.mid(s, (i-s)).toDouble();
        nums.push_back(num);
    }

    // 계산하기
    m_result = nums[0];
    for(i=0; i<opers.size(); i++) {
        if(opers[i] == '+') {
            m_result += nums[i+1];
        } else if(opers[i] == '-') {
            m_result -= nums[i+1];
        } else if(opers[i] == '*') {
            m_result *= nums[i+1];
        } else if(opers[i] == '/') {
            if(nums[i+1] != 0) {
                m_result /= nums[i+1];
            }
        } else if(opers[i] == '%') {
            // 정수인지 확인하기
            // 정수가 아닌 경우, 에러 처리 필요
        }
    }
    m_display->setText(QString("%1").arg(m_result));
}


Widget::~Widget()
{
}

