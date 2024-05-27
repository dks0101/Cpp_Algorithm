#include <iostream>
using namespace std;

int t ,n;
int main(){
    cin>>t;
    while(t--){
        int size_ans =0, round_ans=0;
        int px1, py1, qx1, qy1;
        int px2, py2, qx2, qy2;
        cin>>px1>>py1>>qx1>>qy1;
        cin>>px2>>py2>>qx2>>qy2;
        int size1 = (qx1-px1) * (qy1-py1);
        int size2 = (qx2-px2) * (qy2-py2);
        int round1 = 2*(qx1-px1) + 2*(qy1-py1);
        int round2 = 2*(qx2-px2) + 2*(qy2-py2);
        // 두 사각형이 겹치지 않는 경우
        if (px1 > qx2 || py1 > qy2 || px2 > qx1 || py2 > qy1) {
            int size_ans = size1 + size2;
            int round_ans = round1 + round2;
            cout << size_ans << " " << round_ans << endl;
        }
        //두 사각형이 겹치는 경우
        int common_area = 0;
        if (px1 <= qx2 && qx1 >= px2 && py1 <= qy2 && qy1 >= py2) { // 두 사각형이 겹치는 경우
            int common_left = max(px1, px2);
            int common_right = min(qx1, qx2);
            int common_bottom = max(py1, py2);
            int common_top = min(qy1, qy2);
            common_area = (common_right - common_left) * (common_top - common_bottom);
            int round_ans = round1 + round2 - 2*((common_right - common_left) + (common_top - common_bottom));
            int size_ans = size1 + size2 - common_area;
            cout << size_ans << " " << round_ans << endl;
        }
    }
}
