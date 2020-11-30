/**
 * @brief   approx_sine.c is the source file for a sine approximation that
 *          will run independent of hardware
 * 
 * @author  Josh Bussis
 * @date    2020/10/31
 */

#include "approx_sine.h"


/*
 * @brief   approx_sine takes an input and returns the approximate 
 *          sine value (radians)
 * 
 * @input   x (float)
 * @return  float
 */
float approx_sine_rad(float x)
{
    float theta = x * INVERSE2PI;   /* normalize the theta value for easier calculation */
    theta = theta - (int)theta;     /* keep within the bounds of 0 - 1 */

    return (theta <= 0.5) * ( (-16 * theta * theta) + (8 * theta) )
            + (theta > 0.5) * ( (16 * theta * theta) - (24 * theta) + 8 );
}


/*
 * @brief   approx_sine takes an input and returns the approximate 
 *          sine value (degrees)
 * 
 * @input   x (float)
 * @return  float
 */
float approx_sine_degrees(float x)
{
    x *= CONVERTRAD;                /* convert the input to radians for easier math */
    float theta = x * INVERSE2PI;   /* normalize the theta value for easier calculation */
    theta = theta - (int)theta;     /* keep within the bounds of 0 - 1 */

    return (theta <= 0.5) * ( (-16 * theta * theta) + (8 * theta) )
            + (theta > 0.5) * ( (16 * theta * theta) - (24 * theta) + 8 );
}

