#include <iostream>
#include <queue>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;

    // Step 1
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Step 2
    for (int i = k; i <= r; i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3
    int ans = pq.top();
    return ans;
}

int main() {
    // Example usage
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = kthSmallest(arr, 0, n - 1, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
