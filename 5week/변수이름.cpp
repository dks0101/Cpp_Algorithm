#include <iostream>
#include <string>
using namespace std;

bool is_valid_variable_name(string s) {
    //첫 글자가 숫자인 경우
    if (isdigit(s[0])) {
        return false;
    }
    for (char c : s) {
        // 숫자, 영문자, _ 이 아닌 문자가 포함된 경우
        if (!(isdigit(c) || isalpha(c) || c == '_')) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;
        cout << is_valid_variable_name(s) << endl;
    }
    return 0;
}