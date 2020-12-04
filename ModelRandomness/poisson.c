/***
 *  @brief  poisson.c runs the simulation for dice throws -- Poisson
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
    int nums[16] = {0};                 /* keep track of how many ones are rolled */
    int total;                          /* total number of ones */

    total = 0;                          /* make sure total is zero */
    n = 15;                             /* start with 50 dice */
    iterations = 1000;                  /* number of iterations */

    srand((unsigned) time(&t));         /* initialize rng (seeding with current time) */    

    for (i = 0; i < iterations; ++i) {  /* go through all the iterations */
        for (j = 0; j < n; ++j) {       /* roll all of the dice */
            r = rand() % 6 + 1;         /* get the random num 1 - 6 */
            total += (r == 1);          /* record the number of ones */
        }
        nums[total]++;                  /* add to correct number place in array */
        total = 0;                      /* reset total */
    }

    /* print results */
    printf("Num\tCount\n");
    for (i = 0; i < 16; ++i) {
        printf("%2d\t%3d\n", i, nums[i]);
    }

    return 0;
}
