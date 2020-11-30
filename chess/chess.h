/***
 * chess.h is the header file for chess.c
 *
 * @author  Josh Bussis
 * @date    2020/03/01
 */

#ifndef CHESS_H__
#define CHESS_H__

/**************************** CUSTOM VALUES ***************************/

// piece values
#define KING_VALUE      65535   /* capture value of the king -> basically infinity */
#define QUEEN_VALUE     9       /* capture value of the queen */
#define ROOK_VALUE      5       /* capture value of a rook */
#define BISHOP_VALUE    3       /* capture value of a bishop */
#define KNIGHT_VALUE    3       /* capture value of a knight */
#define PAWN_VALUE      1       /* capture value of a pawn */
#define EMPTY_VALUE     0       /* empty space has no capture value */

// boolean values (for readability)
#define TRUE            1
#define FALSE           0

// directional definitions for checking if the king is in check
#define DIAGONAL        0       /* number code for diagonal used to check if the king is in check */
#define CROSS           1       /* number code for cross used to check if the king is in check */
#define KNIGHTS         2       /* number code for knights used to check if the king is in check */

#define FIRST_DIR       0       /* number code for the first direction to check in a certain orientation */
#define SECOND_DIR      1       /* number code for the second direction to check in a certain orientation */
#define THIRD_DIR       2       /* number code for the third direction to check in a certain orientation */
#define FOURTH_DIR      3       /* number code for the fourth direction to check in a certain orientation */



/**************************** CUSTOM TYPES ****************************/

// enumeration for a piece name
enum Piece {King, Queen, Rook, Bishop, Knight, Pawn, Empty};
// enumeration for a side
enum Side {White, Black, Neutral};

// type for coordinate on the board
typedef struct coord_t
{
    unsigned int x;
    unsigned int y;
} coord_t;

// type to represent a piece
typedef struct piece_t {
    enum Piece type;            /* which kind of piece it is */
    enum Side side;             /* which side the piece is on */
    unsigned int value;         /* value of the piece for scoring purposes */
    char has_moved;             /* keep track of whether the piece has moved */
    coord_t current_position;   /* the current position on the board */
} piece_t;

// type to represent a board
typedef struct board_t
{
    piece_t** board;            /* 2d array of pieces */
    unsigned int white_score;   /* white score based on which black pieces have been taken */
    unsigned int black_score;   /* black score based on which white pieces have been taken */
    unsigned char is_done;      /* keeps track of whether the game is done (1) or still being played (0) */
    enum Side top_side;         /* keep track of the side that is on the top of the board */
} board_t;





/****************************** METHODS ******************************/

/**
 * @brief   buildBoard() makes a new board_t to play chess
 * 
 * @param   side (the side that the player wants to be)
 * @return  board_t
*/
board_t buildBoard(enum Side side);

/**
 * @brief   isValidMove() checks a move for a piece to see if it is valid
 * 
 * @param   board (the current board that is being played on)
 * @param   piece (the piece that is trying to move) 
 * @param   new_coord (the new coordinate that the piece is trying to move to)
 * @return  isValid (1 if the move is valid; 0 if not)
*/
char isValidMove(board_t board, piece_t piece, coord_t new_coord);

/**
 * @brief    makeMove() attempts to move a given piece to a new coordinate
 * 
 * @param   board (the current board that is being played on)
 * @param   piece (the piece that is trying to move) 
 * @param   new_coord (the new coordinate that the piece is trying to move to)
 * @return  void
*/
void makeMove(board_t * board, piece_t piece, coord_t new_coord);

/**
 * @brief   validMoves() finds all the valid moves for a given piece
 * 
 * @param   board (the current board that is being played on)
 * @param   piece (the piece to check moves for)
 * @return  coord_t* (an array of all possible moves)
*/
coord_t* validMoves(board_t board, piece_t piece);

/**
 * @brief   kingIsInCheck() checks if a given king is in check
 * 
 * @param   board (the current board that is being played on)
 * @param   king (the king under question)
 * @return  isInCheck (1 if the king is in check; 0 if not)
*/
char kingIsInCheck(board_t board, piece_t king);

/**
 * @brief   resign() handles when a player resigns
 * 
 * @param   board (the current board that is being played on)
 * @param   user_side (which the player is)
*/
void resign(board_t board, enum Side user_side);


/**
 * @brief   printBoard() prints out a given board to the terminal for the user
 *          to see.
 * 
 * @param   board (the board to be printed out)
 * @return  void
*/
void printBoard(board_t board);

/**
 * @brief   distanceToSide() returns the number of spaces from the king to a 
 *          given side given a certain "looking" paradigm and orientation
 * 
 * @param side (the side of interest)
 * @param paradigm (the way to "look" e.g. diagonal, cross, knights)
 * @param orientation (the orientation of )
*/
unsigned int distanceToSide(char side, char paradigm, char orientation);

#endif
