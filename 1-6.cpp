// Parallel Matrix Multiplication

#include <iostream>
#include <thread>

#define ROWS1   5   
#define COLS1   5   
#define ROWS2   5   
#define COLS2   5   


void matrixMult(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2], int matrix_res[ROWS1][COLS2]) {

    if (COLS1 != ROWS2)
        return;

    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS2; j++) {
            matrix_res[i][j] = 0;
            for (int k = 0; k < ROWS2; k++) {
                matrix_res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

}


int main () 
{ 
    int debug1[ROWS1][COLS1] = {{51,4,6,8,10},{2,7,5,10,4},{49,33,8,19,91},{7,3,5,11,2},{8,12,3,10,16}};
    int debug2[ROWS2][COLS2] = {{7,23,15,8,18},{21,18,9,5,10},{11,1,2,1,11},{1,3,9,10,21},{11,5,2,1,0}};

    int mult_result[ROWS1][COLS2];

    // [51, 4, 6, 8,10] - [ 7,23,15, 8,18]
    // [ 2, 7, 5,10, 4] - [21,18, 9, 5,10]
    // [49,33, 8,19,91] * [11, 1, 2, 1,11]
    // [ 7, 3, 5,11, 2] - [ 1, 3, 9,10,21]
    // [ 8,12, 3,10,16] - [11, 5, 2, 1, 0]
    // array time!!! no more vectors
    // start with 5x5 matrix to check accuracy, THEN apply to big matrix
    
    matrixMult(debug1, debug2, mult_result);


    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS2; j++) {
            std::cout << mult_result[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0; 
}