#include <iostream>
#include <vector>
#include <unordered_map>

int maxFrequency(const std::vector<int>& A) {
    int n = A.size();
    std::unordered_map<int, int> mp;
    int maxFreq = 0;
    int maxAns = 0;

    // Count the frequency of each element
    for (int i = 0; i < n; ++i) {
        mp[A[i]]++;
        maxFreq = std::max(maxFreq, mp[A[i]]);
    }

    // Find the element with the maximum frequency
    for (int i = 0; i < n; ++i) {
        if (maxFreq == mp[A[i]]) {
            maxAns = A[i];
            break; // Break out of the loop once found
        }
    }

    return maxAns;
}

int main() {
    std::vector<int> A = {1, 2, 2, 3, 3, 3, 4, 4, 4};
    int result = maxFrequency(A);
    std::cout << "Element with maximum frequency: " << result << std::endl;

    return 0;
}
