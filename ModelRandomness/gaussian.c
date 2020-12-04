/***
 * @brief  gaussian.c runs the simulation for dice throws -- Gaussian
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
    int i, j, iterations, n;            /* iterator and number of random numbers */
    int r;                              /* random number */
    int nums[51] = {0};                 /* keep track of how many 1-2-3 are rolled */
    int total;                          /* total number of ones, twos, and threes */

    total = 0;                          /* make sure total is zero */
    n = 50;                             /* start with 50 dice */
    iterations = 1000;                  /* number of iterations */

    srand((unsigned) time(&t));         /* initialize rng (seeding with current time) */    

    for (i = 0; i < iterations; ++i) {  /* go through all the iterations */
        for (j = 0; j < n; ++j) {       /* roll all of the dice */
            r = rand() % 6 + 1;         /* get the random num 1 - 6 */
            total += (r == 1);          /* record the number of ones */
            total += (r == 2);          /* record the number of twos */
            total += (r == 3);          /* record the number of threes */
        }
        nums[total]++;                  /* add to correct number place in array */
        total = 0;                      /* reset total */
    }

    /* print results */
    printf("Num\tCount\n");
    for (i = 0; i < 51; ++i) {
        printf("%2d\t%3d\n", i, nums[i]);
    }

    return 0;
}
