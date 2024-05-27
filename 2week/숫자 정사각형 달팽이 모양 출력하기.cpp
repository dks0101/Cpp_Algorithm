#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n;

        // n x n 크기의 배열 동적 할당
        int **pro = new int*[n];
        for(int i = 0; i < n; i++) {
            pro[i] = new int[n];
        }

        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pro[i][j] = num++;
            }
        }

        cin >> a >> b;

        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        int count = 0;

        while(top <= bottom && left <= right) {
            // 왼쪽에서 오른쪽으로 이동 (행 고정, 열 증가)
            for(int j = left; j <= right; j++) {
                count++;
                if(count >= a && count <= b) {
                    cout << pro[top][j] << " ";
                }
            }
            top++;

            // 위쪽에서 아래쪽으로 이동 (열 고정, 행 증가)
            for(int i = top; i <= bottom; i++) {
                count++;
                if(count >= a && count <= b) {
                    cout << pro[i][right] << " ";
                }
            }
            right--;

            // 오른쪽에서 왼쪽으로 이동 (행 고정, 열 감소)
            if(top <= bottom) {
                for(int j = right; j >= left; j--) {
                    count++;
                    if(count >= a && count <= b) {
                        cout << pro[bottom][j] << " ";
                    }
                }
                bottom--;
            }

            // 아래쪽에서 위쪽으로 이동 (열 고정, 행 감소)
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    count++;
                    if(count >= a && count <= b) {
                        cout << pro[i][left] << " ";
                    }
                }
                left++;
            }
        }

        // 동적 할당한 배열 메모리 해제
        for(int i = 0; i < n; i++) {
            delete[] pro[i];
        }
        delete[] pro;

        cout << endl;
    }

    return 0;
}
