/**
 * @brief   telescope.h defines needed constansts and declares functions for the 
 *          telescope project
 * 
 * @author  Josh Bussis
 * @date    2020/09/03
 */

#include <stdio.h>

#ifndef TELESCOPE_H__
#define TELESCOPE_H__

/* CONSTANTS */
#define RIGHT_ASC_MIN   0
#define RIGHT_ASC_MAX   360
#define DECLINATION_MIN -90
#define DECLINATION_MAX 90
#define AZIMUTH_MIN     0
#define AZIMUTH_MAX     359
#define ALTITUDE_MIN    0
#define ALTITDUE_MAX    90
#define SIDEREAL_DAY    0.9972695718    /* solar days */
#define SOLAR_DAY       1.0000000000    /* solar days */
#define SIDEREAL_YEAR   365.256363004   /* solar days (reference point = January 1, 2000) */
#define TROPICAL_YEAR   365.24219       /* solar days */
/* END CONSTANTS */


/* STRUCTS */
/* current coordinates */
typedef struct current_t
{
    double declination;     /* measured in degrees; [-90, 90] */
    double right_ascention; /* measured in degrees; [0, 360) */
    double longitude;       /* current longitude */
    char year;              /* current year */
    char month;             /* current month */    
    char date;              /* current day of month */
    char hour;              /* current hour of the time */
    char minute;            /* current minute of the time */
} current_t;

/* new telescope coordinates */
typedef struct tele_t
{
    double azimuth;     /* measured in degrees; [0, 360) */
    double altitude;    /* measured in degrees; [0, 90] */
} tele_t;
/* END STRUCTS */


/* FUNCTIONS */
void user_input(current_t* current);
void convert_coords(current_t* current, tele_t* new_coords);
void print_results(tele_t new_coords);
/* END FUNCTIONS */



#endif /* end of telescope.h */
