#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& s) {
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

string findNextPalindrome(const string& num) {
    string leftHalf = num.substr(0, num.size() / 2);
    string rightHalf = num.substr((num.size() + 1) / 2);

    string potentialPalindrome = leftHalf + (num.size() % 2 == 0 ? "" : num[num.size() / 2]) + rightHalf;
    
    if (potentialPalindrome > num) {
        return potentialPalindrome;
    } else {
        int carry = 1;
        for (int i = leftHalf.size() - 1; i >= 0; --i) {
            int digit = (leftHalf[i] - '0') + carry;
            leftHalf[i] = '0' + digit % 10;
            carry = digit / 10;
        }

        if (carry > 0) {
            potentialPalindrome = leftHalf + (num.size() % 2 == 0 ? "" : leftHalf[0]) + leftHalf;
        } else {
            potentialPalindrome = leftHalf + (num.size() % 2 == 0 ? "" : leftHalf[0]) + rightHalf;
        }

        return potentialPalindrome;
    }
}

string getNextPalindrome(const string& num) {
    if (isPalindrome(num)) {
        string nextNum = num;
        do {
            nextNum = to_string(stoll(nextNum) + 1);
        } while (!isPalindrome(nextNum));
        return nextNum;
    } else {
        return findNextPalindrome(num);
    }
}

int main() {
    string num = "12345";
    cout << "Next largest palindrome: " << getNextPalindrome(num) << endl;
    return 0;
}
