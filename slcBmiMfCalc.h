#ifndef SLCBMIMFCALC_H
#define SLCBMIMFCALC_H

#include <QString>

/**
 * @brief Simple BMI gender-based calculator
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

class slcBmiMfCalc
{
public:
    /** Enum defining the gender */
    typedef enum
    {
        GENDER_MALE = 0,
        GENDER_FEMALE
    } bmiGenderType;

    slcBmiMfCalc();
    ~slcBmiMfCalc();
    /**
     * @brief calcBmi Calculate the BMI
     * @param weight Specify the weight in [kg]
     * @param height Specify the height in [m]
     * @return A float with the calculated BMI
     */
    float calcBmi(float weight, float height);
    /**
     * @brief setGender Sets the gender of the person
     * @param gender The gender to set.
     */
    void setGender(bmiGenderType gender);
    /**
     * @brief getTextForResult Returns the text for the result
     * @return A QString containing the text.
     */
    QString getTextForResult();
private:
    bmiGenderType m_Gender; ///< Holds the current gender
    float m_Bmi; ///< Holds the last result
    /**
     * @brief getTextForMaleResult Return the text for the male result
     * @return A QString with the text
     */
    QString getTextForMaleResult();
    /**
     * @brief getTextForFemaleResult Return the text for the female result
     * @return A QString with the text
     */
    QString getTextForFemaleResult();
};




#endif //SLCBMIMFCALC_H
