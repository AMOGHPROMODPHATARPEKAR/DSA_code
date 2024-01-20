#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[largest] < a[left]) {
        largest = left;
    }
    if (right < n && a[largest] < a[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // Step 1: Merge both arrays into one
    vector<int> ans = a;
    for (int i = 0; i < b.size(); i++)
        ans.push_back(b[i]);

    int size = n + m;

    // Step 2: Build the heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}

int main() {
    // Example usage
    vector<int> heapA = {10, 5, 12};
    vector<int> heapB = {7, 6, 11};
    int sizeA = heapA.size();
    int sizeB = heapB.size();

    vector<int> mergedHeap = mergeHeaps(heapA, heapB, sizeA, sizeB);

    cout << "Merged Heap: ";
    for (int i = 0; i < mergedHeap.size(); i++) {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}
