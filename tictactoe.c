// Player VS Computer

// MSYS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char PLAYER='X';
const char COMPUTER = 'O';

void playerMove();
void computerMove();
char checkWinner();
int checkFreeSpaces();
void printWinner(char winner);
void printBoard();
void resetBoard();

int main(){
    int c;
    char winner=' ';
    char response = ' ';
    srand(time(0));
    printBoard();
    do{
        winner = ' ';
        response = ' ';
        resetBoard();

        while(winner ==' '  && checkFreeSpaces() != 0){
            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }

            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("Do you want to play again (Y/N): ");
        scanf(" %c", &response);
        while ((c = getchar()) != '\n' && c != EOF);
        response = toupper(response);
    }while(response == 'Y');

    printf("\nThanks for playing");
    return 0;
}

void printBoard(){
    printf(" %c | %c | %c \n",board[0][0], board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0], board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0], board[2][1],board[2][2]);
    printf("\n");
}

void resetBoard(){
    int i,j;
    for(i=0; i<3;i++){
        for(j=0;j<3;j++){
          board[i][j]=' ';  
        }
    }
}

void playerMove(){
    int i,j, c;

    do{
        printf("Enter row  #(1-3): ");
        if(scanf("%d", &i)!=1){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
        }
        i--;

        printf("Enter column  #(1-3): ");
        if(scanf("%d", &j) != 1){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
            continue;
        }
        j--;

        if(i>2 || i<0 || j>2 || j<0 || board[i][j] != ' '){
            printf("Invalid move. Please Enter again.\n");
        }
        else{
            board[i][j]=PLAYER;
        }
    }while(1);
    
}

void computerMove()
{
    int i,j;
    if(checkFreeSpaces() > 0){
        do{
            i = rand() % 3;
            j = rand() % 3;
        }while(board[i][j] != ' ');

        board[i][j] = COMPUTER;
    }
}

char checkWinner(){
    int i;
    //Check rows
    for(i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' '){
            return board[i][0];
        }
    }
    //Check columns
    for(i=0;i<3;i++){
         if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' '){
            return board[0][i];
        }       
    }
    //Check Diagonals
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2] && board[1][1] != ' ' ){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1]==board[2][0] && board[1][1] != ' ' ){
        return board[0][2];
    }

    return ' ';

}

int checkFreeSpaces(){
    int freeSpaces = 9;
    int i,j;
    for(i=0; i<3;i++){
        for(j=0;j<3;j++){
          if(board[i][j] != ' '){
            freeSpaces--;
          }
        }
    }
    return freeSpaces;
}

void printWinner(char winner){
    
    if(winner == PLAYER){
        printf("You won the game.");
    }
    else if(winner == COMPUTER){
        printf("Imagine losing to a computer....");
    }
    else{
        printf("ITS A TIE.");
    }
}