#include <iostream>
using namespace std;

int t, n, sco;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int score[5] = {0, 0, 0, 0, 0};
        for(int i=0;i<n;i++){
            cin>>sco;
            if (sco>=90){
                score[0]++;
            }
            else if(sco>=80){
                score[1]++;
            }
            else if(sco>=70){
                score[2]++;
            }
            else if(sco>=60){
                score[3]++;
            }
            else {
                score[4]++;
            }
        }
        for(int i=0;i<5;i++){
            cout<<score[i]<<" ";
        }
        cout<<endl;
    }
}