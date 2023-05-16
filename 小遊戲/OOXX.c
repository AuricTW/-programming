#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return 0;  // Board is not full
            }
        }
    }
    return 1;  // Board is full
}

int hasWon(char player) {
    int i, j;
    
    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;  // Player has won
        }
    }
    
    // Check columns
    for (j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;  // Player has won
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;  // Player has won
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;  // Player has won
    }
    
    return 0;  // No winner
}

int isValidMove(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;  // Invalid move
    }
    
    if (board[row][col] != '-') {
        return 0;  // Cell already occupied
    }
    
    return 1;  // Valid move
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    
    initializeBoard();
    
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    
    while (1) {
        printf("\n");
        printBoard();
        printf("\n");
        
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        if (!isValidMove(row, col)) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        makeMove(row, col, currentPlayer);
        
        if (hasWon(currentPlayer)) {
        printf("\n");
        printBoard();
        printf("\nPlayer %c wins!\n", currentPlayer);
        break;
        }
    
        if (isBoardFull()) {
        printf("\n");
        printBoard();
        printf("\nIt's a draw!\n");
        break;
        }
    
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

return 0;
} 
