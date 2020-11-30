/**
 * @brief   main.c runs the telescope project
 * 
 * @author  Josh Bussis
 * @date    2020/09/03
 */

#include "telescope.h"

int main(void)
{
    /* variables */
    current_t cur;
    tele_t new_coords;

    for (;;) { /* continually loop for input from the user */
        /* ask the user for input */
        user_input(&cur);
        /* convert coordinates */
        convert_coords(&cur, &new_coords);
        /* print out results */
        print_results(new_coords);
    }

    return 0;
}
