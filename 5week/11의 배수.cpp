#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string str, result;
        cin >> str;

        while (str.length() > 1) {
            char c;
            // 마지막 자리수를 떼어낸다.
            int lastDigit = str.back() - '0';
            str.pop_back();

            // 마지막 자리수를 떼어내어 한 자리가 짧아진 수에서 떼어낸 마지막 수를 뺀다.
            int secondLastDigit = str.back() - '0';
            str.pop_back();

            // 마지막에서 두 번째 수에서 마지막 수를 뺀 수를 다시 str에 더해준다.
            if (lastDigit <= secondLastDigit) {
                int diff = secondLastDigit - lastDigit;
                str += to_string(diff);
            } else if(lastDigit > secondLastDigit) { 
                if (str.back() == '0') { // borrow from higher digits
                int i = str.length() - 1;
                    while (str[i] == '0') {
                        str[i] = '9';
                        i--;
                    } 
                    str[i] = char(str[i] - 1);
                    int carry = 10 + secondLastDigit - lastDigit;
                    str += to_string(carry);
                } else { // no need to borrow
                    str[str.size() - 1] = char(int(str[str.size() - 1]) - 1); 
                    int carry = 10 + secondLastDigit - lastDigit;
                    str += to_string(carry);
                }
            }
            result = char(lastDigit + '0') + result; // 결과 문자열에 해당 자리수 추가
        }
        if (str=="0") {
            if(result[0]!=0){
            while (result[0] == '0' && result.size() > 1) {
            result.erase(result.begin());
            }
        }
        cout << result << endl;          
        } else {
            cout << '0' << endl;
        }
    }
    return 0;
}
