#include <iostream>
#include <vector>
using namespace std;

int t, n;
int main(){
    cin>>t;
    while(t--){
        int cnt =0;
        cin>>n;
        vector<int> prices(n);
        for(int i=0; i<n; i++){
            cin>>prices[i];
        }
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1] && prices[i]>prices[i+1]){
                cout<<prices[i]<<"\n";
                cnt++;
            }
            else if(prices[i] == prices[i-1] && prices[i] > prices[i+1] && prices[i] > prices[i-2]){
                cout<<prices[i]<<"\n";
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}