#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "calculator.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Calculator *cal;

    QPushButton *m_btn_nums[10];
    QPushButton *m_btn_dot;
    QPushButton *m_btn_opers[5];

    QPushButton *m_btn_ac;
    QPushButton *m_btn_back;
    QPushButton *m_btn_history;

    QLineEdit *m_display;

    void display(QString val);
    void display_error(errors err);

private slots:
    // numbers
    void slot_input_0();
    void slot_input_1();
    void slot_input_2();
    void slot_input_3();
    void slot_input_4();
    void slot_input_5();
    void slot_input_6();
    void slot_input_7();
    void slot_input_8();
    void slot_input_9();
    void slot_input_dot();

    // operators
    void slot_input_add();
    void slot_input_sub();
    void slot_input_mul();
    void slot_input_div();
    void slot_input_equal();

    // functions
    void slot_clear();
    void slot_back();
    void slot_history();
};
#endif // WIDGET_H
