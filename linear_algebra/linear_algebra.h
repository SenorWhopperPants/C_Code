/*
 * linear_algebra.h is the header file for linear_algebra.c
 *
 * @author  Josh Bussis
 * @date    12/17/2019
 */

#ifndef LINEAR_ALGEBRA_H__
#define LINEAR_ALGEBRA_H__

// matrix type definition
typedef struct matrix {
    float ** matrix;
    unsigned int rows;
    unsigned int cols;
    int error_code;
} matrix_t;

typedef struct vector {
    float * vector;
    unsigned int length;
    int error_code;
} vector_t;

// matrix functions
matrix_t matrix_addition(matrix_t a, matrix_t b);
matrix_t matrix_subtraction(matrix_t a, matrix_t b);
matrix_t matrix_multiplication(matrix_t a, matrix_t b);
matrix_t transpose(matrix_t a);
matrix_t ref(matrix_t a);
matrix_t rref(matrix_t a);
float    det(matrix_t a);
matrix_t column_space(matrix_t a);
matrix_t row_space(matrix_t a);
matrix_t null_space(matrix_t a);
matrix_t left_null_space(matrix_t a);

// vector functions
vector_t vector_addition(vector_t a, vector_t b);
int      dot_product(vector_t a, vector_t b);
vector_t proj_u_v(vector_t u, vector_t v);
vector_t proj_U_v(matrix_t U, vector_t v);

// extra functions that other functions need to operate
float ** row_swap(matrix_t matrix, int row1, int row2);

// misc. functions
void print_matrix(matrix_t matrix);


#endif
