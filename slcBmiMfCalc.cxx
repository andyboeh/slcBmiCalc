#include "slcBmiMfCalc.h"

slcBmiMfCalc::slcBmiMfCalc()
{
    m_Bmi = 0;
    m_Gender = GENDER_MALE;
}


slcBmiMfCalc::~slcBmiMfCalc()
{

}


float slcBmiMfCalc::calcBmi(float weight, float height)
{
    float ret;
    if(height < .00001) // Float precision limit
        return 0;
    ret = weight / (height * height);
    m_Bmi = ret;
    return ret;
}


void slcBmiMfCalc::setGender(slcBmiMfCalc::bmiGenderType gender)
{
    m_Gender = gender;
}

QString slcBmiMfCalc::getTextForMaleResult()
{
    if(m_Bmi < 20)
        return "too low";
    if(m_Bmi < 26)
        return "normal";
    if(m_Bmi < 31)
        return "too much";
    if(m_Bmi < 41)
        return "Adipositas";
    return "severe Adipositas";
}

QString slcBmiMfCalc::getTextForFemaleResult()
{
    if(m_Bmi < 19)
        return "too low";
    if(m_Bmi < 25)
        return "normal";
    if(m_Bmi < 31)
        return "too much";
    if(m_Bmi < 41)
        return "Adipositas";
    return "severe Adipositas";
}

QString slcBmiMfCalc::getTextForResult()
{
    switch(m_Gender)
    {
    case GENDER_MALE:
        return getTextForMaleResult();
        break;
    case GENDER_FEMALE:
        return getTextForFemaleResult();
        break;
    default:
        return "Unknown Gender";
    }
}
