#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t; 
    while (t--) { 
        int n;
        cin >> n; 
        int rock = 0, scissor = 0, paper = 0;
        int move; 
        for (int i = 0; i < n; i++) {
            cin >> move; 
            if (move == 1) scissor++;
            else if (move == 2) rock++;
            else if (move==3) paper++;
        }
        if(scissor+rock==n){
            if(scissor!=0&&rock!=0){
                cout<<rock<<endl;
            } else if(scissor==0){
                cout << 0 <<endl;
            }
        }
        if(rock+paper==n){
            if(rock!=0&&paper!=0){
                cout<<paper<<endl;
            } else if(rock==0){
                cout << 0 <<endl;
            }
        }
        if(paper+scissor==n){
            if(scissor!=0&&paper!=0){
                cout<<scissor<<endl;
            } else if(paper==0){
                cout << 0 <<endl;
            }
        }
        if(scissor+rock+paper==n && scissor!=0 && rock!=0 && paper!=0){
            cout << 0 <<endl;
        }
    }
}