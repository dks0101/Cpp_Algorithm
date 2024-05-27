#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cnt = 0;
        int sum = 0;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && a[j] >= a[j-1]) {
                j++;
            }
            int len = j - i;
            if (len > 1) {
                cnt++;
                for (int k = i; k < j; k++) {
                    sum += a[k];
                }
            }
            i = j;
        }

        cout << cnt << " " << sum << endl;
    }

    return 0;
}
