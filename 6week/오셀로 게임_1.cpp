#include <iostream>
using namespace std;

const int SIZE = 8;
const char EMPTY = '+';
const char BLACK = 'X';
const char WHITE = 'O';

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void updateBoard(char board[SIZE][SIZE], int row, int col, char color) {
    board[row][col] = color;
}

void flipStones(char board[SIZE][SIZE], int row, int col, char color, int dr, int dc) {
    int r = row + dr;
    int c = col + dc;
    while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] != EMPTY && board[r][c] != color) {
        board[r][c] = color;
        r += dr;
        c += dc;
    }
}

void makeMove(char board[SIZE][SIZE], int row, int col, char color) {
    updateBoard(board, row, col, color);

    int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    for (int i = 0; i < 8; i++) {
        int dr = dirs[i][0];
        int dc = dirs[i][1];

        int r = row + dr;
        int c = col + dc;
        bool validMove = false;
        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] != EMPTY) {
            if (board[r][c] == color) {
                validMove = true;
                break;
            }
            r += dr;
            c += dc;
        }

        if (validMove) {
            flipStones(board, row, col, color, dr, dc);
        }
    }
}

void playOthello() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        char board[SIZE][SIZE];

        // Initialize the board
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = EMPTY;
            }
        }
        board[3][3] = WHITE;
        board[4][4] = WHITE;
        board[3][4] = BLACK;
        board[4][3] = BLACK;

        int n;
        cin >> n;

        // Make moves
        for (int i = 0; i < n; i++) {
            int row, col;
            cin >> row >> col;
            makeMove(board, row - 1, col - 1, (i % 2 == 0) ? BLACK : WHITE);
        }

        // Count the number of black and white stones
        int blackCount = 0, whiteCount = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == BLACK) {
                    blackCount++;
                } else if (board[i][j] == WHITE) {
                    whiteCount++;
                }
            }
        }
        // Print the result
        cout << blackCount << " " << whiteCount << endl;
        printBoard(board);
    }
}

int main() {
    playOthello();
    return 0;
}