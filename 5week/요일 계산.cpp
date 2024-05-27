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
        
        // 1582년 1월 1일부터 총 일수
        int days = (y - 1582) * 365 + (y - 1581) / 4 - (y - 1501) / 100 + (y - 1201) / 400;
        for (int i = 1; i < m; i++) {
            if (i == 2) {
                if (isLeapyear(y)) {
                    days += 29;
                } else {
                    days += 28;
                }
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                days += 30;
            } else {
                days += 31;
            }
        }
        days += d - 1;
        
        // 요일 계산 (0:일요일, 1:월요일, ..., 6:토요일)
        int weekday = (days+5) % 7;
        cout << weekday << endl;
    }
    return 0;
}
