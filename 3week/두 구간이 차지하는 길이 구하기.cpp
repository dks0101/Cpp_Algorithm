#include <iostream>
using namespace std;

int t;
int main(){
    cin>>t;
    while(t--){
        int a, b, c, d;
        int overlap=0, total=0;
        cin>>a>>b>>c>>d;
        if(c<d&&d<a&&a<b){
            overlap = 0;
            total = (b-a) + (d-c);
            cout<<overlap<< " " <<total<<"\n";
        }
        if(c<a&&a<d&&d<b){
            overlap = d-a;
            total = b-c;
            cout<<overlap<< " " <<total<<"\n";
        }
        if(c<a&&a<b&&b<d){
            overlap = b-a;
            total = d-c;
            cout<<overlap<< " " <<total<<"\n";
        }
        if(a<b&&b<c&&c<d){
            overlap = 0;
            total = (b-a) + (d-c);
            cout<<overlap<< " " <<total<<"\n";
        }
        if(a<c&&c<b&&b<d){
            overlap = b-c;
            total = d-a;
            cout<<overlap<< " " <<total<<"\n";
        }
        if(a<c&&c<d&&d<b){
            overlap = d-c;
            total = b-a;
            cout<<overlap<< " " <<total<<"\n";
        }
    }
    return 0;
}
