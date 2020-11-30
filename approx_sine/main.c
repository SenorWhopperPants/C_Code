/**
 * @brief   main.c tests the approx_sine function
 * 
 * @author  Josh Bussis
 * @date    2020/10/31
 */

#include <math.h>
#include <stdio.h>
#include "approx_sine.h"

int main(void)
{
    int i;
    double rad, difference, actual, approx, total_error, average_error;

    total_error = 0;
    printf("Angle  - std_value  - approx  - difference\n");
    /* create test loop to see the accuracy compared to the std library */
    for (i = 0; i <= 360; ++i) {
        rad = i * CONVERTRAD;
        actual = sin(rad);
        approx = approx_sine_rad(rad);
        difference = fabs(actual - approx);
        total_error += difference;
        printf("%d\t%f\t%f\t%f\n", i, actual, approx, difference);
    }

    average_error = total_error / 361;
    printf("Total error accumulated: %f\n", total_error);
    printf("Average error: %f\n", average_error);

    return 0;
}
