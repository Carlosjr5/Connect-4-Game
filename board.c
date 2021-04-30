/*
Created by Carlos Jimenez Rodriguez, Last date modifided: 29/04/2021.
*/

//Getting the definition of each characters.
#include "conect4.h"
#include <stdio.h>


//Create the board with the row and columns.
int makeboard(char board[ROW][COLUMNS]) {
    numberselection(COLUMNS);
    printf("\n");
    int i;
    for (i = 0; i < ROW; ++i) {
        int j;
        for (j = 0; j < COLUMNS; ++j) {
            printf("|%c", board[i][j]);
            if (j + 1 >= COLUMNS) {
                printf("|");
            }
        }
        printf("\n");
    }
    return 0;
}


//Each time there is a line set another column with another number for the user to input where
//he wants the piece to be set at.
void numberselection(int columns) {
    printf("\n");
    int i;
    for (i = 0; i < columns; ++i) {
        printf("|%d", i + 1);
        if (i + 1 >= columns) {
            printf("|");
        }

    }
}


//Making the board empty.
void emptyboard(char board[ROW][COLUMNS]) {
    int i;
    for (i = 0; i < ROW; ++i) {
        int j;
        for (j = 0; j < COLUMNS; ++j) {
            board[i][j] = Empty;
        }
    }
}


//Checking for an empty row.
int emptyrow(int column,char board[ROW][COLUMNS]) {
    int i;
    for (i = ROW - 1; i >= 0; i--) {
        if (board[i][column] == Empty) {
            return i;
        }
    }
    return RowNotFound;
}

//Checking if the column if column and row are free to set the piece.
int setpiece(char player, int column, char board[ROW][COLUMNS]) {
    if (column < 0 || column >= COLUMNS) {
        return InvalidRow;
    }
    int row = emptyrow(column, board);
    if (row == RowNotFound) {
        return ColumnFull;
    }
    board[row][column] = player;
    return NoErrors;
    
    

}


//No one wins so is a tie.
int tie(char board[ROW][COLUMNS]) {
    int i;
    for (i = 0; i < COLUMNS; ++i) {
        int result = emptyrow(i, board);
        if (result != RowNotFound) {
            return 0;
        }
    }
    return 1;
}