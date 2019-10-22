#ifndef SLCBMICALC_H
#define SLCBMICALC_H

/**
 * @brief Simple BMI Calculator
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

class slcBmiCalc
{
public:
    slcBmiCalc();
    ~slcBmiCalc();
    /**
     * @brief calcBmi Calculates the BMI with the given parameters
     * @param weight The weight in [kg] of the person
     * @param height The height in [m] of th eperson
     * @return A float with the calculated BMI
     */
    float calcBmi(float weight, float height);
};




#endif //SLCBMICALC_H
