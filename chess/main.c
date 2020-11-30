/***
 * main.c runs chess game
 * 
 * @author  Josh Bussis
 * @date    2020/03/01
 */

#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char valid_choice = 0;
    enum Side user_side;
    char user_choice[20];
    // ask user which side they want to be
    while (!valid_choice)
    {
        printf("What side do you want to be? (White/Black):\n");
        scanf("%s", user_choice);
        if (strcmp( user_choice, "White") == 0 || strcmp( user_choice, "white") == 0 || strcmp( user_choice, "w") == 0)
        {
            user_side = White;
            valid_choice = 1;
        }
        else if (strcmp( user_choice, "Black") == 0 || strcmp( user_choice, "black") == 0 || strcmp( user_choice, "b") == 0)
        {
            user_side = Black;
            valid_choice = 1;
        }
        else
        {
            printf("*** Please enter a valid side ***\n\n");
        }
    }

    board_t board = buildBoard(user_side);
    printBoard(board);
    return 0;
}
