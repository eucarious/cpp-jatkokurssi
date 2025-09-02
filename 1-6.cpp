// Parallel Matrix Multiplication

#include <iostream>
#include <ctime>
#include <thread>

#define ROWS1   500
#define COLS1   500 
#define ROWS2   500 
#define COLS2   500 


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

void matrixSegmentedMult(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2], int matrix_res[ROWS1][COLS2], int startR, int endR) {

    if (COLS1 != ROWS2)
        return;

    for (int i = startR; i < endR; i++) {
        for (int j = 0; j < COLS2; j++) {
            matrix_res[i][j] = 0;
            for (int k = 0; k < ROWS2; k++) {
                matrix_res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

}

void generateMatrix(int target_matrix[ROWS1][COLS1]) {
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            target_matrix[i][j] = (std::rand() % 25);
        }
    }
}


int main () 
{ 
//     int debug1[5][5] = {{51,4,6,8,10},{2,7,5,10,4},{49,33,8,19,91},{7,3,5,11,2},{8,12,3,10,16}};
//     int debug2[5][5] = {{7,23,15,8,18},{21,18,9,5,10},{11,1,2,1,11},{1,3,9,10,21},{11,5,2,1,0}};

//     int mult_result[5][5];

//     // [51, 4, 6, 8,10] - [ 7,23,15, 8,18]
//     // [ 2, 7, 5,10, 4] - [21,18, 9, 5,10]
//     // [49,33, 8,19,91] * [11, 1, 2, 1,11]
//     // [ 7, 3, 5,11, 2] - [ 1, 3, 9,10,21]
//     // [ 8,12, 3,10,16] - [11, 5, 2, 1, 0]
//     // array time!!! no more vectors
//     // start with 5x5 matrix to check accuracy, THEN apply to big matrix

//     std::thread one(matrixSegmentedMult, debug1, debug2, mult_result, 0, 2);
//     std::thread two(matrixSegmentedMult, debug1, debug2, mult_result, 2, 5);

//     // lil guy works. time to generate a big guy

// two.join();
// one.join();

    std::srand(std::time(0));

    int mult_result[ROWS1][COLS2];

    int big_boy1[ROWS1][COLS1];
    int big_boy2[ROWS2][COLS2];
    generateMatrix(big_boy1);
    generateMatrix(big_boy2);

    std::thread one(matrixSegmentedMult, big_boy1, big_boy2, mult_result, 0, 100);
    std::thread two(matrixSegmentedMult, big_boy1, big_boy2, mult_result, 100, 200);
    std::thread three(matrixSegmentedMult, big_boy1, big_boy2, mult_result, 200, 300);
    std::thread four(matrixSegmentedMult, big_boy1, big_boy2, mult_result, 300, 400);
    std::thread five(matrixSegmentedMult, big_boy1, big_boy2, mult_result, 400, 500);

    one.join();
    two.join();
    three.join();
    four.join();
    five.join();
    
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            std::cout << mult_result[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0; 
}