#include <iostream>
using namespace std;

int t, n, res, a;
int main(){
    cin>>t;
    while (t--){
        cin>>n;
        res = 1;
        while(n--){
            cin>>a;
            res *= a%10;
            res %=10;
        }
        cout << res << "\n";
    }
}