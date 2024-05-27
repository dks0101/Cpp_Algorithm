#include <iostream>
using namespace std;
int t, n, h;
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        h = n/2;
        for(int x=-h;x<=h;x++){
            for(int y=h;y>=-h;y--){
                if(x==0&y==0){
                    cout<<"O";
                }
                else if(y==0) cout<<"I";
                else if(x==0) cout<<"+";
                else if(x==y) cout<<"*";
                else cout<<".";
            }
            cout << "\n";
        }
    }
}