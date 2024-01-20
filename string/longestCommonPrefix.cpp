#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    // for traversing all char of first string
    for (int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;

        // for comparing the rest with ch
        for (int j = 1; j < n; j++) {
            // not match
            if (arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if (match == false) {
            break;
        } else {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main() {
    // Example usage
    vector<string> strings = {"flower", "flow", "flight"};
    int size = strings.size();

    string result = longestCommonPrefix(strings, size);

    // Displaying the result
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
