#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int cnt[101] = {0};
        int num;
        while (cin >> num) {
            if (num == 0) break;
            if (num >= 1 && num <= 100) {
                cnt[num]++;
            }
        }
        int max_num = 0;
        int max_idx = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] > max_num) {
                max_num = cnt[i];
                max_idx = i;
            }
        }
        if (max_num == 0) {
            cout <<"0"<<endl;
        }else {
            for (int i = 1; i <= 100; i++) {
                if (cnt[i] == max_num) {
                    if (i > max_idx) {
                        max_idx = i;
                    }
                }
            }
            cout << max_idx << endl;
        }
    }
    return 0;
}
