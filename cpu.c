/*
Created by Carlos Jimenez Rodriguez, Last date modifided: 29/04/2021.
*/

//Getting the definition of each characters.
#include "conect4.h"
#include <string.h>
#include <stdio.h>

//Clonning the first board.
void clone(char original[ROW][COLUMNS], char new[ROW][COLUMNS]) {
    memcpy(new, original, TAMANIO_MATRIZ);
}

//Checks for the column winner.
int column_winner(char player, char original[ROW][COLUMNS]) {
    char board[ROW][COLUMNS];
    int i;
    for (i = 0; i < COLUMNS; i++) {
        clone(original, board);
        int result = setpiece(player, i, board);
        if (result == NoErrors) {
            int win = winner(player, board);
            if (win != NoConect) {
                return i;
            }
        }
    }
    return winner_column_notfound;
}

//Checks if the row is full for set a piece.
int FullRow(int column, char board[ROW][COLUMNS]) {
    int i;
    for (i = 0; i < ROW; ++i) {
        if (board[i][column] != Empty) {
            return i;
        }
    }
    return RowNotFound;
}


 //Create 2 pointers because not able to get back 2 variables.
 //Checking for the column with more pieces conected.

void column_counter_finder(char player, char original[ROW][COLUMNS], int *count, int *count2) {


    int counting1 = 0, counting2 = -1;

 //Printing board
    char board[ROW][COLUMNS];
    int i;

    for (i = 0; i < COLUMNS; ++i) {
        clone(original, board);
        int status = setpiece(player, i, board);

        if (status == NoErrors) {
            int piece = FullRow(i, board);
            if (piece != RowNotFound) {

                //Checking up with the pieces
            int c = countUp(i, piece, player, board);
                if (c > counting1) {
                    counting1 = c;
                    counting2 = i;
                }
                 //Checking in diagonal to right 
                 c = countUpRight(i, piece, player, board);
                if (c > counting1) {
                    counting1 = c;
                    counting2 = i;
                }

                //Checking to the right.
                c = countRight(i, piece, player, board);
                if (c > counting1) {
                    counting1 = c;
                    counting2 = i;
                }

                //Checking in Diagonal down right
                c = countDownRight(i, piece, player, board);
                if (c > counting1) {
                    counting1 = c;
                    counting2 = i;
                }
            }
        }
    }
    *count = counting1;
    *count2 = counting2;
}

//Setting the piece in a ramdom colum with space.
int ramdom_column(char player, char original[ROW][COLUMNS]) {
    while (1) {
        char board[ROW][COLUMNS];
        clone(original, board);
        int column = ramdom_rand(0, COLUMNS - 1);
        int result = setpiece(player, column, board);
        if (result == NoErrors) {
            return column;
        }
    }
}

//Getting the middle column.
int middle_column(char player, char original[ROW][COLUMNS]) {
    char board[ROW][COLUMNS];
    clone(original, board);
    int half_board = (COLUMNS - 1) / 2;
    int result = setpiece(player, half_board, board);
    if (result == NoErrors) {
        return half_board;
    }
    return winner_column_notfound;
}

//CPU select column.
int cpu_column(char player, char board[ROW][COLUMNS]) {
    // checking for a possible column winner
    int pcw = column_winner(player, board);
    if (pcw != winner_column_notfound) {
        printf("I will win! :)\n");
        return pcw;
    }

    // checking if not if the opponent is able to win with the next movement.
    char opponent = players(player);
    int pcwo = column_winner(opponent, board);
    if (pcwo != winner_column_notfound) {
        printf("You are so smart!!\n");
        return winner_column_notfound;
    }

    // If no one can win next movement, check where to set the piece.
    int countcpu, cpu_column;
    column_counter_finder(player, board, &countcpu, &cpu_column);

    //Checking for the player if it has connect more than the cpu
    int playercount, playercolumn;
    column_counter_finder(opponent, board, &playercount, &playercolumn);
    if (playercount > countcpu) {
        return playercolumn;

    } else if (countcpu > 1) {
        return cpu_column;
    }

    // Go back to the middle in case is free.
    int mid = middle_column(player, board);
    if (mid != winner_column_notfound) {
        return mid;
    }
    // Checking for a free place to set the piece.
    int column = ramdom_column(player, board);
    if (column != RowNotFound) {
        return column;
    }

    return 0;
}