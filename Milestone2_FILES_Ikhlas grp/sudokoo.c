#include <stdio.h>
#include <stdint.h>

#define SIZE 9
volatile uint32_t tohost = 0;
int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

void showBoard(int board[SIZE][SIZE]);
int isSafe(int row, int col, int board[SIZE][SIZE], int num);
int solveBoard(int board[SIZE][SIZE]);
int isBoardFull(int board[SIZE][SIZE]);

int main(int argc, char* argv[]) {

    if (solveBoard(board)) {
        //printf("SOLVED\n");
        showBoard(board);
    } else {
        //printf("Unsuccessful\n");
    }

    return 0;
}

void showBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solveBoard(int board[SIZE][SIZE]) {
    int row, col; //defining for loop parameters

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(row, col, board, num)) {
                        board[row][col] = num;

                        if (solveBoard(board)) {
                            return 1;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int isBoardFull(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int row, int col, int board[SIZE][SIZE], int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == num) {
            return 0;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void _start()
{
    main(0, 0);
    tohost = 1;
}

