#include <stdio.h>

/* print Celsius-Fahrenheit table
    for Celsius = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of table */
    upper = 300;    /* upper limit of table */
    step = 20;      /* step size */

    celsius = lower;
    printf(" C  |  F\n");
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
