#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int overlap = max(0, min(b, d) - max(a, c));
        int total = (b - a) + (d - c) - overlap;

        cout << overlap << " " << total << "\n";
    }
}
