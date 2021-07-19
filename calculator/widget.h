#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

enum errors { div_zero, others };

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    enum m_opers {
        add='+', sub='-', mul='*', div='/'
    };

    QPushButton *m_btn_nums[10];
    QPushButton *m_btn_dot;
    QPushButton *m_btn_opers[6];

    QPushButton *m_btn_ac;
    QPushButton *m_btn_back;

    QLineEdit *m_display;

    QVector<double> nums;
    QVector<QChar> opers;
    double m_result;

    void calculate(QString calLine);
    void setValues(QString calLine);
    double getResult();

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
    void slot_input_rem();
    void slot_input_equal();

    // functions
    void slot_clear();
    void slot_back();
};
#endif // WIDGET_H
