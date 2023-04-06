#include <stdio.h>

#define ROWS 8
#define COLUMNS 8

int grid[ROWS][COLUMNS];

void print_grid() {
    int i, j;
    printf("   1     2    3   4   5   6   7   8\n");
    printf(" +------------------------+\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d| ", i + 1);
        for (j = 0; j < COLUMNS; j++) {
            printf("%c | ", grid[i][j]);
        }
        printf("\n +------------------------+\n");
    }
    printf("\n");
}

int main() {
    int i, j, player = 1, row, col;
    char piece;
    // initialize grid with spaces
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }

    // set initial pieces
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                grid[i][j] = 'o';
            } else if ((i + j) % 2 == 1 && i > 4) {
                grid[i][j] = 'x';
            }
        }
    }

    // game loop
    while (1) {
        // print grid
        print_grid();

        // get player's move
        printf("Player %d's turn.\n", player);
        printf("Enter row and column of piece to move: ");
        scanf("%d %d", &row, &col);

        // check if piece belongs to player and is a valid piece
        if (grid[row - 1][col - 1] != (player == 1 ? 'o' : 'x')) {
            printf("Invalid piece. Please try again.\n");
            continue;
        }

        // get player's move destination
        printf("Enter row and column of destination: ");
        scanf("%d %d", &i, &j);

        // check if move is valid
        if (i < 1 || i > 8 || j < 1 || j > 8) {
            printf("Invalid destination. Please try again.\n");
            continue;
        }
        if (grid[i - 1][j - 1] != ' ') {
            printf("Destination already occupied. Please try again.\n");
            continue;
        }
        if (player == 1 && i <= row) {
            printf("Invalid move. Pieces can only move forward. Please try again.\n");
            continue;
        }
        if (player == 2 && i >= row) {
            printf("Invalid move. Pieces can only move forward. Please try again.\n");
            continue;
        }
        if ((i + j) % 2 == 0) {
            printf("Invalid move. Pieces can only move on dark squares. Please try again.\n");
            continue;
        }

        // move piece
        piece = grid[row - 1][col - 1];
        grid[row - 1][col - 1] = ' ';
        grid[i - 1][j - 1] = piece;

        // check for victory
        // ...

        // switch player
        player = (player == 1 ? 2 :1);
    }
}
