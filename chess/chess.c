/***
 * chess.c contains methods for chess functions
 *
 * @author  Josh Bussis
 * @date    2020/03/01
 */

#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief   buildBoard() makes a new board_t to play chess
 * 
 * @param   side (the side that the player wants to be)
 * @return  board_t
*/
board_t buildBoard(enum Side side)
{
    piece_t** pieces;           /* new 2d array of pieces */
    unsigned int score = 0;     /* the score starts at 0 for both sides */
    char not_done = 0;          /* the game is just starting, so the game is not done */
    enum Side top_side;

    // allocate memory for the board (eventually change this to a normal array instead of 2d)
    pieces = (piece_t **)malloc(8 * sizeof(piece_t *));
    for (unsigned int i = 0; i < 8; ++i)
    {
        pieces[i] = (piece_t *)malloc(8 * sizeof(piece_t));
    }

    // based on the side, assign pieces
    if (side == White)
    {
        // white side is facing player
        top_side = Black;
        // assign black value pieces
        pieces[0][0] = (piece_t){ .type = Rook, .side = Black, .value = ROOK_VALUE};
        pieces[0][1] = (piece_t){ .type = Knight, .side = Black, .value = KNIGHT_VALUE};
        pieces[0][2] = (piece_t){ .type = Bishop, .side = Black, .value = BISHOP_VALUE};
        pieces[0][3] = (piece_t){ .type = Queen, .side = Black, .value = QUEEN_VALUE};
        pieces[0][4] = (piece_t){ .type = King, .side = Black, .value = KING_VALUE};
        pieces[0][5] = (piece_t){ .type = Bishop, .side = Black, .value = BISHOP_VALUE};
        pieces[0][6] = (piece_t){ .type = Knight, .side = Black, .value = KNIGHT_VALUE};
        pieces[0][7] = (piece_t){ .type = Rook, .side = Black, .value = ROOK_VALUE};
        // assign black pawns
        pieces[1][0] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][1] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][2] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][3] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][4] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][5] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][6] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[1][7] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        // assign blank spaces
        pieces[2][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        // assign white pawns
        pieces[6][0] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][1] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][2] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][3] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][4] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][5] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][6] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[6][7] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        // assign white value pieces
        pieces[7][0] = (piece_t){ .type = Rook, .side = White, .value = ROOK_VALUE};
        pieces[7][1] = (piece_t){ .type = Knight, .side = White, .value = KNIGHT_VALUE};
        pieces[7][2] = (piece_t){ .type = Bishop, .side = White, .value = BISHOP_VALUE};
        pieces[7][3] = (piece_t){ .type = Queen, .side = White, .value = QUEEN_VALUE};
        pieces[7][4] = (piece_t){ .type = King, .side = White, .value = KING_VALUE};
        pieces[7][5] = (piece_t){ .type = Bishop, .side = White, .value = BISHOP_VALUE};
        pieces[7][6] = (piece_t){ .type = Knight, .side = White, .value = KNIGHT_VALUE};
        pieces[7][7] = (piece_t){ .type = Rook, .side = White, .value = ROOK_VALUE};
    }
    else
    {
        // black side is facing player
        top_side = White;
        // assign white value pieces
        pieces[0][0] = (piece_t){ .type = Rook, .side = White, .value = ROOK_VALUE};
        pieces[0][1] = (piece_t){ .type = Knight, .side = White, .value = KNIGHT_VALUE};
        pieces[0][2] = (piece_t){ .type = Bishop, .side = White, .value = BISHOP_VALUE};
        pieces[0][3] = (piece_t){ .type = King, .side = White, .value = KING_VALUE};
        pieces[0][4] = (piece_t){ .type = Queen, .side = White, .value = QUEEN_VALUE};
        pieces[0][5] = (piece_t){ .type = Bishop, .side = White, .value = BISHOP_VALUE};
        pieces[0][6] = (piece_t){ .type = Knight, .side = White, .value = KNIGHT_VALUE};
        pieces[0][7] = (piece_t){ .type = Rook, .side = White, .value = ROOK_VALUE};
        // assign white pawns
        pieces[1][0] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][1] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][2] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][3] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][4] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][5] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][6] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        pieces[1][7] = (piece_t){ .type = Pawn, .side = White, .value = PAWN_VALUE};
        // assign blank spaces
        pieces[2][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[2][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[3][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[4][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][0] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][1] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][2] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][3] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][4] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][5] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][6] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        pieces[5][7] = (piece_t){ .type = Empty, .side = Neutral, .value = EMPTY_VALUE};
        // assign black pawns
        pieces[6][0] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][1] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][2] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][3] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][4] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][5] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][6] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        pieces[6][7] = (piece_t){ .type = Pawn, .side = Black, .value = PAWN_VALUE};
        // assign black value pieces
        pieces[7][0] = (piece_t){ .type = Rook, .side = Black, .value = ROOK_VALUE};
        pieces[7][1] = (piece_t){ .type = Knight, .side = Black, .value = KNIGHT_VALUE};
        pieces[7][2] = (piece_t){ .type = Bishop, .side = Black, .value = BISHOP_VALUE};
        pieces[7][3] = (piece_t){ .type = King, .side = Black, .value = KING_VALUE};
        pieces[7][4] = (piece_t){ .type = Queen, .side = Black, .value = QUEEN_VALUE};
        pieces[7][5] = (piece_t){ .type = Bishop, .side = Black, .value = BISHOP_VALUE};
        pieces[7][6] = (piece_t){ .type = Knight, .side = Black, .value = KNIGHT_VALUE};
        pieces[7][7] = (piece_t){ .type = Rook, .side = Black, .value = ROOK_VALUE};
    }

    return (board_t){ .board = pieces, .white_score = score, .black_score = score, .is_done = not_done, .top_side = top_side };

}


/**
 * @brief   printBoard() prints out a given board to the terminal for the user
 *          to see.
 * 
 * @param   board (the board to be printed out)
 * @return  void
*/
void printBoard(board_t current_board)
{
    // define two-character names for pieces w/ two space padding
    char* king      = " KG |";
    char* queen     = " QN |";
    char* rook      = " RK |";
    char* bishop    = " BP |";
    char* knight    = " KT |";
    char* pawn      = " PN |";
    char* empty     = "    |";
    char* spacer    = "-----------------------------------------\n";
    char* left      = "|";

    // go through all the pieces on the board and print them out
    for (int i = 0; i < 8; ++i)
    {
        printf("%s", spacer);
        printf("%s", left);
        for (int j = 0; j < 8; ++j)
        {
            switch (current_board.board[i][j].type)
            {
                case King:
                    printf("%s", king);
                    break;

                case Queen:
                    printf("%s", queen);
                    break;

                case Rook:
                    printf("%s", rook);
                    break;

                case Bishop:
                    printf("%s", bishop);
                    break;

                case Knight:
                    printf("%s", knight);
                    break;

                case Pawn:
                    printf("%s", pawn);
                    break;

                case Empty:
                    printf("%s", empty);
                    break;
            }
        }
        printf("\n");
    }
    printf("%s", spacer);
}

/**
 * @brief   isValidMove() checks a move for a piece to see if it is valid
 * 
 * @param   board (the current board that is being played on)
 * @param   piece (the piece that is trying to move) 
 * @param   new_coord (the new coordinate that the piece is trying to move to)
 * @return  isValid (1 if the move is valid; 0 if not)
*/
char isValidMove(board_t board, piece_t piece, coord_t new_coord)
{
    // check what type of piece we're dealing with
    switch (piece.type)
    {
        case King:
            // check that the king only moves by one square
            if ( abs(piece.current_position.x - new_coord.x) <= 1 && abs(piece.current_position.y - new_coord.y) <= 1)
            {
                // check that a piece of the same color isn't in the new position
                if ( board.board[new_coord.x][new_coord.y].side == piece.side) {
                    return 0;
                }
                else
                {
                    // check that this doesn't put the king in check
                    
                }
            }
            else
            {
                // handle castling
            }
            break;
        case Queen:

            break;
        case Rook:

            break;
        case Bishop:

            break;
        case Knight:

            break;
        case Pawn:

            break;
        case Empty:
            // can't move an empty space
            return 0;
            break;
    }
}

/**
 * @brief    makeMove() attempts to move a given piece to a new coordinate
 * 
 * @param   board (the current board that is being played on)
 * @param   piece (the piece that is trying to move) 
 * @param   new_coord (the new coordinate that the piece is trying to move to)
 * @return  void
*/
void makeMove(board_t * board, piece_t piece, coord_t new_coord)
{
    
}

/**
 * @brief   kingIsInCheck() checks if a given king is in check
 * 
 * @param   board (the current board that is being played on)
 * @param   king (the king under question)
 * @return  isInCheck (1 if the king is in check; 0 if not)
*/
char kingIsInCheck(board_t board, piece_t king)
{
    char valid_position = TRUE;
    char x_pos = king.current_position.x;
    char y_pos = king.current_position.y;
    char temp_x = ++x_pos;
    char temp_y = ++y_pos;
    char direction = 0;
    char new_direction = 0;
    piece_t piece_to_check;

    // check diagonal
    while (valid_position)
    {
        // assign the piece to check
        piece_to_check = board.board[temp_x][temp_y];
        // check if the king can see a piece
        if (piece_to_check.type != Empty)
        {
            // check if the side is the same as the king
            if (piece_to_check.side == king.side)
            {
                ++new_direction;
            }
            else
            {
                switch (piece_to_check.type)
                {
                    case Queen:
                        return TRUE;

                    case Bishop:
                        return TRUE;

                    case Pawn:
                        if (board.top_side == king.side)
                        {
                            // pawn has to be below the king to take it
                            if (y_pos - temp_y == 1 && abs(x_pos - temp_x) == 1)
                            {
                                return TRUE;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            // pawn has to be above the king to take it
                            if (temp_y - y_pos == 1 && abs(temp_x - x_pos) == 1)
                            {
                                return TRUE;
                            }
                            else
                            {
                                break;
                            }
                        }
                        
                    default:
                        break;
                }
            }
            
        }

        // update the position
        if (new_direction != direction) /* changing checking direction */
        {
            switch (new_direction)
            {
                // move in a clock-wise fasion
                case 1:
                    
            }
        }
        else
        {

        }
    }

    // reset check variables
    valid_position = TRUE;
    direction = 0;

    // check cross

    // check knight
}



