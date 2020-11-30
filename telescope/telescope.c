/**
 * @brief   telescope.c defines the functions found in telescope.h
 * 
 * @author  Josh Bussis
 * @date    2020/09/03
 */

#include "telescope.h"


/*
 * @brief   user_input() gets the needed user information about 
 *          the current date, location, and wanted celestial coords
 * 
 * @param   current (current_t*): a type to store the current info in
 * @return  void
 */
void user_input(current_t* current)
{
    /* wait for the user to input the needed data */

    /* check if they want to quit */

    /* store the data from the user in *current */
}


/*
 * @brief   convert_coords() takes the info from the user and
 *          converts the celestial coords to spherical coords
 *          that a telescope could use
 * 
 * @param   current (current_t*): the info gotten from the user
 *              in the user_input() function
 * @param   new_coords (tele_t*): a place to store the new coords
 *              that the telescope can use
 */
void convert_coords(current_t* current, tele_t* new_coords)
{
    /* check critical declination and latitude first (filter out any that are not visible) */
    
}


/*
 * @brief   print_results() prints out the converted coordinates
 *          in a nice format
 * 
 * @param   new_coords (tele_t): the new coordinates for the telescope
 * @return  void
 */
void print_results(tele_t new_coords)
{

}
