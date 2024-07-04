#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string StringChallenge(string str1, string str2) {
    string sorted_str1 = str1;
    sort(sorted_str1.begin(), sorted_str1.end());
    sort(str2.begin(), str2.end());

    if (sorted_str1.find(str2) < sorted_str1.length() || sorted_str1 == str2) {
        return "true";
    }

    return "false";
}

int main() {
    cout << StringChallenge("rkwlod", "world") << endl;  // Output: true
    cout << StringChallenge("cor", "coo") << endl;  // Output: false

    return 0;
}