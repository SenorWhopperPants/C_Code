/***
 * @brief   main.c drives the sieve program and tests the functionality of 
 *          sieve
 * 
 * @author  Josh Bussis
 * @date    2020/11/18
 */

#include "sieve.h"
#include <stdio.h>


int main(void)
{
    int * ret;
    int max, size;
    char user_choice[6];

    /* ask the user for the max number */
    printf("What is the max number to check: \n");
    scanf("%s", user_choice);                   /* store the input stream in user_choice */
    max = atoi(user_choice);                    /* convert user_choide to int and store in max */

    ret = malloc(max * sizeof(int) - 1);        /* allocate mem for ret array */

    size = sieve(max, ret);                     /* call sieve on max and store results in ret */

    printf("Primes between 2 and %d: \n", max);
    for (int i = 0; i < size; ++i)
        printf("%d\n", ret[i]);                 /* print out the results */

    free(ret);                                  /* make sure to deallocate space for this array */

    return 0;
}
