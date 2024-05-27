#include <iostream>
using namespace std;

int main(){
    unsigned int t,n,l,result;
    cin>>t;
    for(int i=0; i<t;i++){
        cin>>n;

        while(n>=10){
            result=1;
            while(n!=0){
                if(n%10 !=0)
                    result *= (n%10);
                n/=10;
            }
            n=result;
        }
        cout<<n<<endl;
    }
}