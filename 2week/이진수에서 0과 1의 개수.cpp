#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int cnt0 = 0, cnt1 = 0;
        while(n > 0) {
            if(n % 2 == 0) cnt0++; 
            else cnt1++;
            n /= 2;
        }

        cout << cnt0 << " " << cnt1 << endl;
    }

}
