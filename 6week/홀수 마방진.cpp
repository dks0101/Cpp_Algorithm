#include <iostream>
#include <vector>
using namespace std;

void sham(int n) {
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> square(n, vector<int>(n, 0)); // n x n 크기의 0으로 초기화된 2차원 벡터 생성
        int num = 1; // 마방진에 채워질 수
        int row = 0, col = n / 2; // 시작 위치
        while (num <= n * n) {
            square[row][col] = num;
            num++;
            int next_row = (row - 1 < 0) ? n - 1 : row - 1;
            int next_col = (col + 1 == n) ? 0 : col + 1;
            if (square[next_row][next_col] != 0) { // 이미 다른 수가 채워져 있는 경우
                row = (row + 1 == n) ? 0 : row + 1;
            }
            else {
                row = next_row;
                col = next_col;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
