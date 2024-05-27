#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    string stored_digits;

    while (num.size() > 1) {
        stored_digits.push_back(num.back()); // 1.1
        int last_digit = num.back() - '0'; // 문자를 숫자로 변환
        num.pop_back(); // 1.1
        int second_last_digit = num.back() - '0'; // 문자를 숫자로 변환
        num.pop_back(); // 1.2
        int new_digit = second_last_digit - last_digit;
        if (new_digit < 0) new_digit += 10;
        num.push_back(new_digit + '0'); // 숫자를 문자로 변환해서 push_back
    }

    if (num == "0") {
        string quotient_str(stored_digits.rbegin(), stored_digits.rend());
        int quotient = stoi(quotient_str);
        cout << "The given number is divisible by 11 and the quotient is " << quotient << endl;
    }
    else {
        cout << "The given number is not divisible by 11" << endl;
    }

    return 0;
}
