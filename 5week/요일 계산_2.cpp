#include <iostream>
using namespace std;

int isLeapyear(int year) {
    if((year%4==0 && year%100!=0) || year %400==0){
        return 1;
    } else{
        return 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int y, m, d;
        cin >> y >> m >> d;
        int i, sum = 0;
        // 1582년 1월 1일부터 총 일수
        for (i = 1582; i < y; i++) {
            sum += 365 + isLeapyear(i);
        }
        for (int i = 1; i < m; i++) {
            if (i == 2) {
                if (isLeapyear(y)) {
                    sum += 29;
                } else {
                    sum += 28;
                }
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                sum += 30;
            } else {
                sum += 31;
            }
        }
        sum += d-1;
        
        // 요일 계산
        int weekday = (sum+5) % 7;
        cout << weekday << endl;
    }
    return 0;
}
