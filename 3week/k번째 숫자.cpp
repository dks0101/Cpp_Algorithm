#include <iostream>
using namespace std;

int t;
int main() {
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int cnt = 0;//현재까지 더한 자릿수 더한 값
        int now = 1;//현재 확인하고 있는 수
        while (true) {
            int num = now;
            int num_digits = 0;
            while (num > 0) {
                num_digits += 1;
                num /= 10;
            }
            int new_count = cnt + num_digits;
            if (new_count >= k) {
                int diff = k - cnt - 1;
                int num = now + diff / num_digits;
                int digit_idx = num_digits - diff % num_digits - 1;
                for (int i = 0; i < digit_idx; i++) {
                    num /= 10;
                }
                int kth_digit = num % 10;
                cout <<kth_digit << endl;
                break;
            }
            cnt = new_count;
            now += 1;
        }
    }
}
