#include "conect4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Stack {
    char board[COLUMNS];
    int top;
    int column;
};

void printStack ( struct Stack *stack) ;
void push ( struct Stack *stack, int item );
int pop ( struct Stack *stack) ;




//Selecting player turn.
char players(char player) {
    if (player == player_1) {
        return player_2;
    } else {
        return player_1;
    }
}

//Returns a random number between min (included) and max (excluded)
int ramdom_rand(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

//If is 0 is select player_1 if is 1 select player
char ramdomplayer() {
    int numero = ramdom_rand(0, 1);
    if (numero) {
        return player_1;
    } else {
        return player_2;
    }
}



//Asking for the column to the player
  int askforcolumn() {
 FILE *fp;
 fp = fopen("players.txt", "a");
 int count = 0;
 if(fp == NULL)
 {
    printf("Error loading player.txt\n");
 }

    int column = 0;
    //stack = column;

    printf("Type the column number you will like to set your piece: ");
    scanf("%d", &column);
    if (column > 7 || column < 1){
         printf("Try again between 1-7! :) -> ");
    scanf("%d", &column);
    }
        
    fprintf(fp, "%d", column);
    //fclose(fp,"\n");
   
    //column = pop (& stack); 
 //if(stack) { printf (" Item popped : %d\n",  column); } 



    //int i;

   // fp = fopen("players.txt", "r");

    //for (i = 1 ; fgets(column,sizeof(column),fp) != NULL; i++){

           // printf("%02d : %s", i, column);
  //  }
    //     fclose (fp);
        
       column--;
       return column;
}
/*
int count=0;



// Add elements into stack
void push(struct Stack *stack, int item) {
      
if(stack -> top == COLUMNS -1)
 {
 printf (" Stack is full . Couldn ’t push ’%d’ onto stack \n", item );
 return ;
 }
 stack -> top ++;
 stack -> board [stack -> top ] = item ;

    printf("%d pushed to stack\n", item);
  
  count++;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Remove element from stack
int pop(struct Stack *stack) {
   int * data ; if(stack -> top == -1)
 {
 printf (" Stack is empty \n");
 return NULL ;
 }
 data = &stack -> board [stack -> top ];
 stack -> top --;
 return data ;
}

 //Print elements of stack
void printStack(struct Stack *stack) {
  printf("Stack: ");
  stack -> top = -1;

}
*/
