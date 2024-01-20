#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<node*, vector<node*>, compare> minheap;

    // Step 1: All array 1st element into minheap
    for (int i = 0; i < kArrays.size(); i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minheap.push(temp);
    }

    vector<int> ans;

    // Step 2: Merge arrays using minheap
    while (minheap.size() > 0) {
        node* temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        int i = temp->row;
        int j = temp->col;

        // Check if there's a next element in the same array
        if (j + 1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j + 1], i, j + 1);
            minheap.push(next);
        }
    }

    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> kArrays = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 7, 8}
    };

    int k = kArrays.size();

    vector<int> result = mergeKSortedArrays(kArrays, k);

    cout << "Merged Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
