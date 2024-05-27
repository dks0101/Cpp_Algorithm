#include <iostream>
using namespace std;

int t, n, a, s;
int main(){
    cin >> t;
    while(t--){
        cin>>n;
        s=0;
        for(int i=0;i<n;i++){
            cin>>a;
            s+=a;
        }
        cout << s<<"\n";
    }
}