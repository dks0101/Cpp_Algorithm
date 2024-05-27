#include <iostream>

using namespace std;

int main() {
    int t; // 테스트 케이스 개수
    cin >> t;
    
    while (t--) {
        int p1x, p1y, q1x, q1y; // 첫 번째 사각형 꼭지점 좌표
        int p2x, p2y, q2x, q2y; // 두 번째 사각형 꼭지점 좌표
        int area1, area2, border, area3; // 면적, 테두리 길이
        int over_x = max(0, min(q1x, q2x) - max(p1x, p2x));
        int over_y = max(0, min(q1y, q2y) - max(p1y, p2y));
        int over_area=0;
        
        // 첫 번째 사각형 입력 받기
        cin >> p1x >> p1y >> q1x >> q1y;
        // 두 번째 사각형 입력 받기
        cin >> p2x >> p2y >> q2x >> q2y;
        
        // 첫 번째 사각형 면적 계산
        area1 = (q1x - p1x) * (q1y - p1y);
        // 두 번째 사각형 면적 계산
        area2 = (q2x - p2x) * (q2y - p2y);
        
        // 두 사각형이 겹치는 부분이 없을 때
        if (q1x < p2x || q2x < p1x || q1y < p2y || q2y < p1y) {
            border = 2 * ((q1x - p1x) + (q1y - p1y) + (q2x - p2x) + (q2y - p2y));
            area3 = area1 + area2;
        }
        // 두 사각형이 겹치는 부분이 있을 때
        int common_area = 0;
        if (p1x <= q2x && q1x >= p2x && p1y <= q2y && q1y >= p2y) { // 두 사각형이 겹치는 경우
            int common_left = max(p1x, p2x);
            int common_right = min(q1x, q2x);
            int common_bottom = max(p1y, p2y);
            int common_top = min(q1y, q2y);
            common_area = (common_right - common_left) * (common_top - common_bottom);
            cout<<common_area<<endl;
            border = 2 * ((q1x - p1x) + (q1y - p1y) + (q2x - p2x) + (q2y - p2y) - 
                          (min(q1x, q2x) - max(p1x, p2x)) - (min(q1y, q2y) - max(p1y, p2y)));
        }
        int total_area = area1 + area2 - common_area;
        cout << total_area << " " << border << endl;
    }
}
