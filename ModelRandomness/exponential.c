/***
 * @brief  exponential.c runs the simulation for dice throws -- Exponential
 * 
 * @author  Josh Bussis
 * @date    2020/12/3
 */

#include <stdio.h>      /* printf() */
#include <stdlib.h>     /* srand() and rand() */
#include <time.h>       /* time_t */


/* main function of program */
int main(void)
{
    time_t t;                           /* need the current time to seed rand() */
    int i, j, n;                        /* iterators and number of random numbers */
    int roll;                           /* random roll of dice */
    int num_ones;                       /* counter for the number of ones in a group of throws */

    num_ones = 0;                       /* initialize number of ones to zero */
    n = 1000;                           /* start with 1000 dice */
    i = 0;                              /* start iterator at 0 */

    srand((unsigned) time(&t));         /* initialize rng (seeding with current time) */    

    printf("Step\tNumber of dice left\n");
    while (n > 0) {                     /* loop until there are no more dice to roll */
        for (j = 0; j < n; ++j) {       /* roll all of the dice */
            roll = rand() % 6 + 1;      /* get the random num 1 - 6 */
            num_ones += (roll == 1);    /* record the number of ones */
        }
        printf("%3d\t%4d\n", i++, n);   /* print remaining dice */
        n -= num_ones;                  /* how many dice to throw next */
        num_ones = 0;                   /* reset the number of ones */
    }

    return 0;
}
