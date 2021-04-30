/*
Created by Carlos Jimenez Rodriguez, Last date modifided: 29/04/2021.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conect4.h"
#include "finder.c"
#include "board.c"
#include "players.c"
#include "cpu.c"

//Main function.
int main() {
    
    int mode;
    printf("==============================\n");
    printf("==========CONNECT 4===========\n");
    printf("===Carlos Jimenez Rodriguez===\n");
    printf("==============================\n");
    printf("1 => Play 1v1\n"
           "2 => Play against CPU\n"
           "3 => Exit\n"
           "Select an option: ");
    scanf("%d", &mode);
    if (mode <= 0 || mode > 2) {
        return 0;
    }
    play(mode);
return 0;

}

//The function where set the game.
void play(int mode) {
    char board[ROW][COLUMNS];
    //Print the empty board created.
    emptyboard(board);
    char actualPlayer = ramdomplayer(); //Select the player who starts.
    printf("Starts player %c\n", actualPlayer);
    while (1) {
        int column = 0;
        printf("\nPlayer turn %c\n", actualPlayer);
        makeboard(board);
        if (mode == player_vs_CPU) {  //Checking the mode inputed to play, in this case against CPU.
            if (actualPlayer == CPU) {
                printf("CPU thinking...");
                column = cpu_column(actualPlayer, board);
            } else {
                column = askforcolumn();
            } 
            }else if (mode == player1_vs_player2) { //Playing 1v1
            column = askforcolumn();
        }

            //Checking for the status of the column or row where the player want to set the piece.
        int status = setpiece(actualPlayer, column, board);
        if (status == ColumnFull) {
            printf("Error!!: Column Full");
        } else if (status == InvalidRow) {
            printf("Incorrect Row");
        } else if (status == NoErrors) {
            int g = winner(actualPlayer, board);
            if (g != NoConect) {
                makeboard(board);
                printf("Wins player %c.", actualPlayer);
                break;
            } else if (tie(board)) {
                makeboard(board);
                printf("Tie");
                break;
            }
        }
        actualPlayer = players(actualPlayer);
    }
}



     
  






