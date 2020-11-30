/*
 * main.c runs matrix multiplication testing
 * 
 * @author  Josh Bussis
 * @date    12/17/2019
 */

#include "linear_algebra.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

    /* LIST OF TEST MATRICES
        test1    test2      test3
        | 1 |   | 1  1 |  
        | 1 |
    */
    unsigned int rows = 3; 
    unsigned int cols = 3;
    float ** test1;
    // allocate memory for the matrix
    test1 = (float **)malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; ++i) {
        test1[i] = (float *)malloc(cols * sizeof(float));
    }

    test1[0][0] = 3;
    test1[0][1] = 0;
    test1[0][2] = 1;
    test1[1][0] = 2;
    test1[1][1] = 3;
    test1[1][2] = 5;
    test1[2][0] = 4;
    test1[2][1] = 7;
    test1[2][2] = 9;

    float ** test2;
    // allocate memory for the matrix
    test2 = (float **)malloc(rows * sizeof(float *));
    for (unsigned int i = 0; i < rows; ++i) {
        test2[i] = (float *)malloc(cols * sizeof(float));
    }

    test2[0][0] = 5;
    test2[0][1] = 7;
    test2[0][2] = 8;
    test2[1][0] = 8;
    test2[1][1] = 2;
    test2[1][2] = -5;
    test2[2][0] = 1;
    test2[2][1] = 1;
    test2[2][2] = 1;
    // float test1[3][3] = {{3, 0, 1}, {2, 3, 5}, {4, 7, 9}};
    // float test2[3][3] = {{5, 7, 8}, {8, 2, -5}, {1, 1, 1}};
    matrix_t matrix1 = { .matrix = test1, .rows = rows, .cols = cols, 0};
    matrix_t matrix2 = { .matrix = test2, .rows = rows, .cols = cols, 0};
    matrix_t result = matrix_multiplication(matrix1, matrix2);
    matrix_t result2 = transpose(matrix1);

    printf("\n");
    int row = result.rows;
    int col = result.cols;

    print_matrix(result);
    printf("\n\n");

    print_matrix(result2);
    printf("\n\n");    

    // test that swapping rows works
    matrix1.matrix = row_swap(matrix1, 2, 0);
    print_matrix(matrix1);


    // everything ran normally
    return 0;
}