#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    // Initialize the min heap with the first element of each row
    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    mini = min(mini, minHeap.top()->data);

    int start = mini;
    int end = maxi;

    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        int r = temp->row;
        int c = temp->col;

        // Update end and start
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // Check if there is a next element in the row
        if (c + 1 < n) {
            maxi = max(maxi, a[r][c + 1]);
            minHeap.push(new Node(a[r][c + 1], r, c + 1));
        } else {
            // Break if we reach the end of a row
            break;
        }
    }

    return (end - start + 1);
}

int main() {
    int k = 3;
    int n = 4;

    vector<vector<int>> a = {{1, 3, 5, 7},
                             {2, 4, 6, 8},
                             {0, 9, 10, 11}};

    int result = kSorted(a, k, n);

    cout << "Length of the smallest range containing at least one element from each row: " << result << endl;

    return 0;
}
