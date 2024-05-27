#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, s, t;
        cin >> r >> s >> t;

        int A[r][s], B[s][t], C[r][t];
        // 첫 번째 행렬 입력 받기
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < s; j++) {
                cin >> A[i][j];
            }
        }
        // 두 번째 행렬 입력 받기
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                cin >> B[i][j];
            }
        }

        // 행렬 곱셈 연산
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < t; j++) {
                C[i][j] = 0;
                for (int k = 0; k < s; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // 결과 출력
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < t; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
