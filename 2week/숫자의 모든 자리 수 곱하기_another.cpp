#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long num, digit[100], count = 0;
        int ans = 1;
        cin >> num;

        while(num > 0) {
            digit[count] = num % 10;
            num /= 10;
            count++;
        }

        for(int i=count-1; i>=0; i--) {
            if(digit[i]!=0) {
                ans *= digit[i];
            }
        }

        int ans_count = 0; // 새로운 변수 선언
        while(ans>=10) {
            ans_count = 0; // ans_count 변수 초기화
            while(ans > 0) {
                digit[ans_count] = ans % 10;
                ans /= 10;
                ans_count++;
            }
            ans = 1; // ans 변수 초기화
            for(int i=ans_count-1; i>=0; i--) {
                if(digit[i]!=0) {
                    ans *= digit[i];
                }
            }
        }

        cout << ans << endl;
    }
}
