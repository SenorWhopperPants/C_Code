/**
 * @brief   main.c runs the Ackermann function
 *          Ackermann function: one of the simplest and 
 *          earliest examples of a total computable function
 *          that is not primitive recursive (from Wikipedia page)
 * 
 * @author  Josh Bussis
 * @date    2020/11/13 
 */

#include <stdio.h>

#define DEPTH   4   /* WARNING: program gets big FAST, don't go above 4 */

long ackermann(long m, long n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann(m-1, 1);
    else
        return ackermann(m-1, ackermann(m, n-1));
}

int main(void)
{
    for (long i = 0; i < DEPTH; ++i)
        for (long j = 0; j < DEPTH; ++j)
            printf("Ackermann(%ld, %ld) = %ld\n", i, j, ackermann(i, j));
}
