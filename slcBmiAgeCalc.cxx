#include "slcBmiAgeCalc.h"

slcBmiAgeCalc::slcBmiAgeCalc()
{
    m_Age = 0;
    m_Bmi = 0;
}

slcBmiAgeCalc::~slcBmiAgeCalc()
{

}


float slcBmiAgeCalc::calcBmi(float weight, float height)
{
    float ret;
    if(height < .00001) // Float precision limit
        return 0;
    ret = weight / (height * height);
    m_Bmi = ret;
    return ret;
}

void slcBmiAgeCalc::setAge(int age)
{
    m_Age = age;
}

QString slcBmiAgeCalc::getTextForAgeWithNormalValues(int low, int high)
{
    if(m_Bmi < low)
        return "too low";
    if(m_Bmi > high)
        return "too much";
    return "normal";
}

QString slcBmiAgeCalc::getTextForResult()
{
    if(m_Age < 19)
        return "I do not know this age";
    if(m_Age < 25)
        return getTextForAgeWithNormalValues(19, 24);
    if(m_Age < 35)
        return getTextForAgeWithNormalValues(20, 25);
    if(m_Age < 45)
        return getTextForAgeWithNormalValues(21, 26);
    if(m_Age < 55)
        return getTextForAgeWithNormalValues(22, 27);
    if(m_Age < 65)
        return getTextForAgeWithNormalValues(23, 28);

    return getTextForAgeWithNormalValues(24, 29);

}
