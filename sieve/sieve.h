/***
 * @brief   sieve.h function declarations and definitons to
 *                  implement the sieve algorithm to find
 *                  prime numbers
 * 
 * @author  Josh Bussis
 * @date    2020/11/18 
 */

#ifndef SIEVE_H__
#define SIEVE_H__

#include <stdlib.h>

/* FUNCTION DECLARATIONS */
int sieve(int max, int * ret);


/* FUNCTION DEFINITIONS */

/**
 * @brief   takes in a max number and finds all the primes up to,
 *          and including, that number
 *          (precondition: max num is positive, and ret has been
 *                          allocated space to fit max number of 
 *                          integers)
 * 
 * @param   max (int: precondition: max >= 2)
 * @param   ret (int*: precondition: ret has been allocated space
 *                      for max (the variable) integers)
 * @return  count (int: the number of primes)
 */
int sieve(int max, int * ret)
{
    int * temp;
    int end, index, count;
    count = 0;                                  /* make sure count starts at 0 */

    temp = malloc(max * sizeof(int) - 1);       /* allocate mem for temp array */
    for (int i = 2; i < max+1; ++i)             /* fill temp with values */
        temp[i-2] = i;

    for (int i = 0; i < max-1; ++i) {           /* go through the array and sieve out non-primes */
        if (temp[i] != 0) {
            end = max / temp[i];                /* calculate how many multiples of current value there can be */
            for (int j = 1; j < end; ++j) {     /* loop through all mulitples of current value and clear them */
                index = i + (temp[i] * j);      /* calculate new index */
                temp[index] = 0;                /* clear at that index */
            }
        }
    }

    index = 0;                                  /* reset index to 0 */
    count = 0;                                  /* reset count to 0 */

    for (int i = 0; i < max-1; ++i) {           /* take all the valid values in temp, and store in ret */
        if (temp[i] != 0) {                     /* if theres a valid value */
           ret[index++] = temp[i];              /* store value in ret */
           ++count;
        }
    }

    ret = realloc(ret, count * sizeof(int));    /* re-allocate space for ret/trim off uneeded space at the end*/

    free(temp);                                 /* deallocate space for temp */
    return count;                               /* return the number of primes */
}


#endif /* end of sieve.h */
