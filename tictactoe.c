#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main() {
    int c;
    char winner = ' ';
    char response = ' ';
    srand(time(0));

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("You are X. Enter row and column numbers (1-3) to place your mark.\n\n");

    do {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpaces() > 0) {
            printBoard();
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
                break;

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
                break;
        }

        printBoard();
        printWinner(winner);

        printf("\nDo you want to play again (Y/N): ");
        scanf(" %c", &response);
        while ((c = getchar()) != '\n' && c != EOF);
        response = toupper(response);
        printf("\n");

    } while (response == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

void playerMove() {
    int i, j, c;
    while (1) {
        printf("Enter row #(1-3): ");
        if (scanf("%d", &i) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
            continue;
        }
        i--;

        printf("Enter column #(1-3): ");
        if (scanf("%d", &j) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
            continue;
        }
        j--;

        if (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != ' ') {
            printf("Invalid move. Please enter again.\n");
        } else {
            board[i][j] = PLAYER;
            break;
        }
    }
}

void computerMove() {
    int i, j;
    if (checkFreeSpaces() > 0) {
        do {
            i = rand() % 3;
            j = rand() % 3;
        } while (board[i][j] != ' ');

        board[i][j] = COMPUTER;
        printf("Computer placed at row %d, column %d\n", i + 1, j + 1);
    }
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        // Check columns
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

int checkFreeSpaces() {
    int freeSpaces = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                freeSpaces++;
    return freeSpaces;
}

void printWinner(char winner) {
    if (winner == PLAYER)
        printf("You won the game!\n");
    else if (winner == COMPUTER)
        printf("Computer won the game. Better luck next time!\n");
    else
        printf("It's a tie!\n");
}