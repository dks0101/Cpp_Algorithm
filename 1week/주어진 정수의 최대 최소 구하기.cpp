#include <iostream>
using namespace std;

int t, n, mx, mn, a;
int main() {
    cin >> t;
    while (t--){
        cin>>n;
        mx=mn=a;
        for(int x=1;x<n;x++){
            cin>>a;
            if(mx<a){
                mx = a;
            }
            if (mn>a){
                mn =a;
            }
        }
        cout << mx << " " << mn << "\n";
    }
}