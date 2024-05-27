#include <iostream>
using namespace std;

char emp = '+';
char black = 'X';
char white = 'O';

void printboard(char board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void move(char board[8][8], int row, int col, char color) {
    board[row][col] = color;

    int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    for (int i = 0; i < 8; i++) {
        int dr = dirs[i][0];
        int dc = dirs[i][1];

        int r = row + dr;
        int c = col + dc;
        bool move_1 = false;
        while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] != emp) {
            if (board[r][c] == color) {
                move_1 = true;
                break;
            }
            r += dr;
            c += dc;
        }

        if (move_1) {
            int r = row + dr;
            int c = col + dc;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] != emp && board[r][c] != color) {
                board[r][c] = color;
                r += dr;
                c += dc;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        char board[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = emp;
            }
        }
        board[3][3] = white;
        board[4][4] = white;
        board[3][4] = black;
        board[4][3] = black;
        int n;
        cin >> n;
        for (int i = 0; i<n; i++) {
            int row, col;
            cin >> row >> col;
            move(board, row - 1, col - 1, (i % 2 == 0) ? black : white);
        }

        int blackcnt = 0, whitecnt = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == black) {
                    blackcnt++;
                } else if (board[i][j] == white) {
                    whitecnt++;
                }
            }
        }
        cout << blackcnt << " " << whitecnt << endl;
        printboard(board);
    }
    return 0;
}