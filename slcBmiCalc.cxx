#include "slcBmiCalc.h"

slcBmiCalc::slcBmiCalc()
{

}


slcBmiCalc::~slcBmiCalc()
{

}


float slcBmiCalc::calcBmi(float weight, float height)
{
    float ret;
    if(height < .00001) // Float precision limit
        return 0;
    ret = weight / (height * height);
    return ret;
}
