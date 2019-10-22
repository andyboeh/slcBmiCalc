#ifndef SLCBMIAGECALC_H
#define SLCBMIAGECALC_H

#include <QString>

/**
 * @brief Simple BMI Age-based Calculator
 * @author Andreas Böhler
 * @date 2015/05/02
 */

/*
 * Simple BMI Calculator for demonstration purposes only.
 * (c) 2015 - Andreas Böhler, R'n'B Medical Software Consulting GmbH
 * For lecture use only.
 * Normal values are taken from bmi-rechner.net
 *
 * License: WTFPL
 *
 */


class slcBmiAgeCalc
{
public:
    slcBmiAgeCalc();
    ~slcBmiAgeCalc();
    /**
     * @brief calcBmi Calculate the BMI with the given parameters
     * @param weight The weight in [kg] of the person
     * @param height The height in [m] of the person
     * @return A float with the calculated BMI
     */
    float calcBmi(float weight, float height);
    /**
     * @brief setAge Sets the age of the given person
     * @param age The age to set
     */
    void setAge(int age);
    /**
     * @brief getTextForResult Returns the text for the current result and age
     * @return A QString with the text
     */
    QString getTextForResult();
private:
    int m_Age; ///< Holds the current age
    float m_Bmi; ///< Holds the current result
    /**
     * @brief getTextForAgeWithNormalValues Retuns the text for the stored result and normal range
     * @param low The normal range low value
     * @param high The normal range high value
     * @return A QString with the text
     */
    QString getTextForAgeWithNormalValues(int low, int high);
};




#endif //SLCBMIMFAGECALC_H
