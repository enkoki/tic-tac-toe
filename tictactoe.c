// Player VS Computer

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

const char PLAYER='X';
const char COMPUTER = 'O';

void printBoard(){

}
void resetBoard(){

}

int main(){

    char winner=' ';
    char response = ' ';
    srand(time(0));

    do{
        resetBoard();


        printf("Do you want to play again (Y/N): ");
        scanf("%c", &response);
        response = toupper(response);
    }while(response == 'Y');

    printf("\nThanks for playing");
    return 0;
}