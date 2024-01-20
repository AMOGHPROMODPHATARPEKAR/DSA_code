#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minCost(long long arr[], long long n) {
    // Min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long cost = 0;

    // Push elements into the min heap
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    // Merge elements until the heap has only one element
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long temp = a + b;
        cost += temp;
        pq.push(temp);
    }

    return cost;
}

int main() {
    // Example usage
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    long long result = minCost(arr)
}