/* main.c runs the simulation for dice throws */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* parses the cmd line arguments and returns desired number of rolls */
int cmdline(int argc, char** argv)
{
    if (argc == 1) {
        return 10;
    }
    else if (argc == 2) {
        return atoi(argv[1]);
    }
    else {
        fprintf(stderr, "usage: ./dice [numRolls]\n");
        exit(1);
    }
}

/* main function of program */
int main(int argc, char** argv)
{
    time_t t;           /* need the current time to seed rand() */
    int i, n;           /* iterator and number of random numbers */
    int r;              /* random number */
    int nums[6] = {0};  /* keep track of how many of each num are rolled */

    n = cmdline(argc, argv);    /* get the number of rolls */

    srand((unsigned) time(&t)); /* initialize rng */    

    for (i = 0; i < n; ++i) {
        r = rand() % 6 + 1;     /* get the random num */
        nums[r - 1]++;          /* record it */
        printf("%d\n", r);      /* print it out */
    }

    /* print the results */
    printf("Num - How many rolled\n");
    for (i = 0; i < 6; ++i) {
        printf("%d----------%d\n", (i+1), nums[i]);
    }

    return 0;
}
