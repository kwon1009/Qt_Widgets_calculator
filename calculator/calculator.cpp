#include "calculator.h"

Calculator::Calculator(int n)
{
    m_result = 0;
    nums.clear();
    opers.clear();
}

QString Calculator::getErrorMessage(errors err)
{
    QString str = "Error: ";
    switch(err) {
        case div_zero:
            str += "It cannot be divided by zero.";
            break;
        default:
            str += "It is Invalid Format.";
            break;
    }
    return str;
}

void Calculator::setValues(QString calLine)
{
    int i;
    int s = 0;
    for(i=0; i<calLine.length(); i++) {
        // 연산자 구분
        if(!calLine[i].isNumber() && calLine[i] != '.') {
            opers.push_back(calLine[i]);
            double num = calLine.mid(s, (i-s)).toDouble();
            s = i + 1;
            nums.push_back(num);
        }
    }
    if(s >= i) throw others;

    double num = calLine.mid(s, (i-s)).toDouble();
    nums.push_back(num);
}


double Calculator::getResult()
{
    double result = nums[0];
    for(int i=0; i<opers.size(); i++) {
        if(opers[i] == '+') {
            m_result += nums[i+1];
        } else if(opers[i] == '-') {
            m_result -= nums[i+1];
        } else if(opers[i] == '*') {
            m_result *= nums[i+1];
        } else if(opers[i] == '/') {
            if(nums[i+1] == 0) throw div_zero;
            m_result /= nums[i+1];
        } else if(opers[i] == '%') {
            // 정수인지 확인하기
            // 정수가 아닌 경우, 에러 처리 필요
        }
    }
    return result;
}

double Calculator::calculate(QString calLine)
{
    nums.clear();
    opers.clear();

    setValues(calLine);

    if(nums.size() != opers.size()+1) throw others; // 입력한 수식이 정상적인지 확인

    // 계산하기
    m_result = getResult();
    return m_result;
}
