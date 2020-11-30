/**
 * linear_algebra.c contains methods for linear algebra functions
 *
 * @author  Josh Bussis
 * @date    12/7/2019
 */

#include "linear_algebra.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief   matrix_addition() takes in two matricies and adds them together
 *
 * @param   a (first matrix)
 * @param   b (second matrix)
 * @param   a_dim (a's row x col dimmensions -> [rows, cols])
 * @param   b_dim (b's row x col dimmensions -> [rows, cols])
 * @return  resulting matrix
 */
matrix_t matrix_addition(matrix_t a, matrix_t b) {
    // declare local variables
    unsigned int rows1 = a.rows;
    unsigned int rows2 = b.rows;
    unsigned int cols1 = a.cols;
    unsigned int cols2 = b.cols;
    printf("rows1: %d, rows2: %d, cols1: %d, cols2: %d\n", rows1, rows2, cols1, cols2);
    // make result matrix and dim
    float ** result_matrix;
    // allocate memory for the matrix
    result_matrix = (float **)malloc(rows1 * sizeof(float *));
    for (unsigned int i = 0; i < rows1; ++i) {
        result_matrix[i] = (float *)malloc(cols1 * sizeof(float));
    }
    // encapsulate in matrix_t type
    matrix_t result = { .matrix = result_matrix, .rows = rows1, .cols = cols1, .error_code = 0 };

    // check that the dimmensions are the same
    if (rows1 == rows2 && cols1 == cols2) {
        for (unsigned int i = 0; i < rows1; ++i) { // rows
            for (unsigned int j = 0; j < cols1; ++j) { // cols
                result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
                printf("%f\n", result.matrix[i][j]);
            }
        }
        // indicate no error
        result.error_code = 0;
        return result;
    }
    else {
        // indicate that there was an error
        result.error_code = -1;
        return result;

    }
}


/**
 * @brief   matrix_subtraction() takes in two matricies and subtracts them
 *
 * @param   a (first matrix)
 * @param   b (second matrix)
 * @param   a_dim (a's row x col dimmensions -> [rows, cols])
 * @param   b_dim (b's row x col dimmensions -> [rows, cols])
 * @return  resulting matrix
 */
matrix_t matrix_subtraction(matrix_t a, matrix_t b) {
    // declare local variables
    unsigned int rows1 = a.rows;
    unsigned int rows2 = b.rows;
    unsigned int cols1 = a.cols;
    unsigned int cols2 = b.cols;
    printf("rows1: %d, rows2: %d, cols1: %d, cols2: %d\n", rows1, rows2, cols1, cols2);
    // make result matrix and dim
    float ** result_matrix;
    // allocate memory for the matrix
    result_matrix = (float **)malloc(rows1 * sizeof(float *));
    for (unsigned int i = 0; i < rows1; ++i) {
        result_matrix[i] = (float *)malloc(cols1 * sizeof(float));
    }
    // encapsulate in matrix_t type
    matrix_t result = { .matrix = result_matrix, .rows = rows1, .cols = cols1, .error_code = 0 };

    // check that the dimmensions are the same
    if (rows1 == rows2 && cols1 == cols2) {
        for (unsigned int i = 0; i < rows1; ++i) { // rows
            for (unsigned int j = 0; j < cols1; ++j) { // cols
                result.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
                printf("%f\n", result.matrix[i][j]);
            }
        }
        // indicate no error
        result.error_code = 0;
        return result;
    }
    else {
        // indicate that there was an error
        result.error_code = -1;
        return result;

    }
}



/**
 * @brief   matrix_multiplication() takes in two matricies and multiplies them together
 *
 * @param   a (first matrix)
 * @param   b (second matrix)
 * @param   a_dim (a's row x col dimmensions -> [rows, cols])
 * @param   b_dim (b's row x col dimmensions -> [rows, cols])
 * @return  resulting matrix
 */
matrix_t matrix_multiplication(matrix_t a, matrix_t b) {
    unsigned int rows = a.rows;
    unsigned int cols = b.cols;
    // make result matrix and dim
    //float result_matrix[rows][cols];
    float ** result_matrix;
    // allocate memory for the matrix
    result_matrix = (float **)malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; ++i) {
        result_matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    //unsigned int result_dim[2] = { rows, cols }; // changing this from rows, cols
    // encapsulate in matrix_t type
    matrix_t result = { .matrix = result_matrix, .rows = rows, .cols = cols, .error_code = 0 };
    int sum = 0;
    // check that the dimmensions are allowed
    if (a.cols == b.rows) {
        // loop through the matricies (row-major ordering)
        for (unsigned int i = 0; i < a.rows; ++i) {
            for (unsigned int k = 0; k < b.cols; ++k) {
                for (unsigned int j = 0; j < a.cols; ++j) {
                    sum += a.matrix[i][j] * b.matrix[j][k];
                }
                // assign the sum to the correct position in the result matrix
                result.matrix[i][k] = sum;
                // reset the sum variable
                sum = 0;
            }
        }

        result.error_code = 0;
        return result;
    }
    else {
        // return an error
        result.error_code = -1;
        return result;
    }
}

/**
 * @brief transpose() takes in a matrix and returns the transpose of that matrix
 *
 * @param  a (the matrix)
 * @return transpose (the transpose of a)
 */
matrix_t transpose(matrix_t a) {
    unsigned int rows = a.cols;
    unsigned int cols  = a.rows;
    float ** result_matrix;
    // allocate memory for the matrix
    result_matrix = (float **)malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; ++i) {
        result_matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    // loop through the original matrix and store the transpose in the new matrix
    for (unsigned int i = 0; i < cols; ++i) {
        for (unsigned int j = 0; j < rows; ++j) {
            result_matrix[j][i] = a.matrix[i][j];
        }
    }

    matrix_t transpose = { .matrix = result_matrix, .rows = rows, .cols = cols, .error_code = 0 };
    return transpose;
}


/**
 * @brief rref() takes a matrix and returns its reduced row eschelon form
 * 
 * @param a (the input matrix)
 * @return the rref matrix
 */
matrix_t rref(matrix_t a) {
    // needed variables
    unsigned int rows = a.rows;
    unsigned int cols = a.cols;
    float ** result_matrix; // NOTE: could probably just statically allocate this matrix
    char finished = 0; // variable for knowing when to stop Gaussian Elimination
    unsigned int current_row = 0;
    unsigned int current_col = 0;
    char swapped = 0;
    float inverse;

    // allocate memory for the matrix
    result_matrix = (float **)malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; ++i) {
        result_matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    
    // fill the result_matrix with the original values
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result_matrix[i][j] = a.matrix[i][j];
        }
    }

    // pack the matrix in the correct type
    matrix_t result = { .matrix = result_matrix, .rows = rows, .cols = cols, .error_code = 0 };

    // do Gaussian elimination on the matrix
    while(!finished) {
        // check if the current row's first term is zero
        if (result.matrix[current_row][current_col] == 0) {
            // need to find another row that does have a value in current_col
            for (unsigned int i = 0; i < result.rows; ++i) {
                if (result.matrix[i][current_col] != 0) {
                    // we found a non-zero entry, swap the rows
                    result.matrix = row_swap(result, current_row, i);
                    swapped = 1; // indicate that we swapped rows
                    break;
                }
            }
            // check if no rows were swapped; if there weren't, that indicated this whole column is empty
            if (!swapped) {
                // increment to the next row and column
                ++current_row;
                ++current_col;
                swapped = 0; // reset for next iteration
            }
            else {
                // make sure the first entry is == 1
                inverse = 1 / result.matrix[current_row][current_col];
                for (unsigned int i = 0; i < result.cols; ++i) {
                    result.matrix[current_row][i] *= inverse;
                }

                // go through all rows and subtract by the current_row values
                for (unsigned int i = 0; i < result.rows; ++i) {
                    if (i != current_row) { // only want to do this with other rows
                        for (unsigned int j = 0; j < result.cols; ++j) {
                            result.matrix[i][j] -= result.matrix[current_row][j];
                        }   
                    }
                }
            }
        }
        else if (0/* fill in*/) {

        }
        // finally, nothing happened so we are done
        else {
            finished = 1;
        }
    }
}


/**
 * @brief row_swap() takes a matrix and swaps two given rows
 * 
 * @param matrix (the input matrix)
 * @param row1  (number for the first row)
 * @param row2  (number for the second row)
 * @return the same matrix, but row1 and row2 are swapped
 */
float ** row_swap(matrix_t matrix, int row1, int row2) {
    // make a float as a temperary holder of values
    float temp;

    // store the values of the rows
    for (unsigned int i = 0; i < matrix.cols; ++i) {
        // put the first value into the temp variable 
        temp = matrix.matrix[row1][i];
        // move the value of row2 to row1
        matrix.matrix[row1][i] = matrix.matrix[row2][i];
        // take the value in temp and store it in row2
        matrix.matrix[row2][i] = temp;
    }
    return matrix.matrix;
}


/**
 * @brief print_matrix() prints out the values in a matrix nicely
 * 
 * @param matrix (the matrix to print out)
 * @return void
*/
void print_matrix(matrix_t matrix) {
    for (unsigned int i = 0; i < matrix.rows; ++i) {
        printf("|\t");
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            printf("%f\t", matrix.matrix[i][j]);
        }
        printf("|\n\n");
    }
}
