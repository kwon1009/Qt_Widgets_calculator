#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QVector>

enum errors { alpha, blank, div_zero, others };

class Calculator {
    enum m_opers {
        add='+', sub='-', mul='*', div='/'
    };

    QVector<double> nums;
    QVector<QChar> opers;
    double m_result;
    QString m_lastCal;

    void setValues(QString calLine);
    double getResult();

    void cal_mul(int i);
    void cal_div(int i);

public:
    Calculator();

    double calculate(QString calLine);
    QString getLastCal();
    QString getErrorMessage(errors err);
};

#endif // CALCULATOR_H
