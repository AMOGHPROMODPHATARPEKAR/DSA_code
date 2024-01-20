#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void solve(Node* root, int k, int &count, int currentSum, unordered_map<int, int> &prefixSum)
{
    if (root == NULL) {
        return;
    }

    // Update the currentSum for the current node
    currentSum += root->data;

    // Check if there is a prefix sum in the hash table that satisfies the condition
    if (prefixSum.find(currentSum - k) != prefixSum.end()) {
        count += prefixSum[currentSum - k];
    }

    // Update the hash table
    prefixSum[currentSum]++;

    // Recursively traverse the left and right subtrees
    solve(root->left, k, count, currentSum, prefixSum);
    solve(root->right, k, count, currentSum, prefixSum);

    // Backtrack: Remove the currentSum from the hash table before returning
    prefixSum[currentSum]--;
}

int sumK(Node* root, int k)
{
    int count = 0;
    int currentSum = 0;
    unordered_map<int, int> prefixSum;

    solve(root, k, count, currentSum, prefixSum);

    return count;
}

int main()
{
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 8;
    cout << "Count of paths with sum " << k << ": " << sumK(root, k) << endl;

    return 0;
}
