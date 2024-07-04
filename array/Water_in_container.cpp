#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int water = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        water = max(water, h * w);

        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return water;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;  // Output: 49
    return 0;
}
