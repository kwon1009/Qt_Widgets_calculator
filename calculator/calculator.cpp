#include "calculator.h"
#include <QDebug>

Calculator::Calculator()
{
    m_result = 0;
    m_lastCal = "0";
    nums.clear();
    opers.clear();
}

QString Calculator::getErrorMessage(errors err)
{
    QString str = " Error: ";
    switch(err) {
        case alpha:
            str += "Alphabet is not allowed.";
        break;
        case blank:
            str += "Blanks cannot be entered.";
        break;
        case div_zero:
            str += "Can't be divided by zero.";
        break;
        default:
            str += "It is Invalid Format.";
        break;
    }
    return str;
}

QString Calculator::getLastCal()
{
    return m_lastCal;
}

void Calculator::setValues(QString calLine)
{
    int i;
    int s = 0;
    for(i=0; i<calLine.length(); i++) {
        if(calLine[i].isLetter()) throw alpha;  // 알파벳을 입력한 경우
        if(calLine[i] == ' ') throw blank;      // 띄어쓰기 에러 처리

        // 연산자 구분
        if(!calLine[i].isNumber() && calLine[i] != '.') {
            opers.push_back(calLine[i]);
            QString num = calLine.mid(s, (i-s));

            if(num == "") throw others;         // 연산자를 연속으로 입력한 경우

            s = i + 1;
            nums.push_back(num.toDouble());
        }
    }
    if(s >= calLine.length()) throw others;    // 연산자로 끝난 경우

    double num = calLine.mid(s, (i-s)).toDouble();
    nums.push_back(num);
}

void Calculator::resetValue(int i)
{
    nums.erase(nums.begin()+i+1);
    opers.erase(opers.begin()+i);
}

double Calculator::getResult()
{
    int i;

    // 곱셈과 나눗셈 먼저 계산
    i=0;
    while(i<opers.size()) {
        if(opers[i] == mul) {
            nums[i] = nums[i] * nums[i+1];
            resetValue(i);

        } else if(opers[i] == div) {
            if(nums[i+1] == 0) throw div_zero;  // 0으로 나누는 경우
            nums[i] = nums[i] / nums[i+1];
            resetValue(i);

        } else {
            i++;
        }
    }

    // 덧셈과 뺄셈 계산
    for(i=0; i<opers.size(); i++) {
        if(opers[i] == add) {
            nums[i] = nums[i] + nums[i+1];
            resetValue(i);

        } else if(opers[i] == sub) {
            nums[i] = nums[i] - nums[i+1];
            resetValue(i);

        } else {
            throw others;
        }
    }
    return nums[0];
}

double Calculator::calculate(QString calLine)
{
    m_lastCal = calLine;
    nums.clear();
    opers.clear();

    setValues(calLine);

    if(nums.size() != opers.size()+1) throw others; // 입력한 수식이 정상적인지 확인

    // 계산하기
    m_result = getResult();
    return m_result;
}
