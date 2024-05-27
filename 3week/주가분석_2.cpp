#include <iostream>
using namespace std;

int t, n;
int main(){
    cin>>t;
    while(t--){
        int a=100,b=100, c=100;
        int ans=0, rep;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>rep;
            if(c!=rep){
                a=b;b=c;
                c=rep;
                if(b>a&&b>c){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}