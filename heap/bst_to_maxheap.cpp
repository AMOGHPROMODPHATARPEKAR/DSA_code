#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int>& a) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

void bstTomax(Node* root, vector<int>& a, int& index) {
    if (root == nullptr) {
        return;
    }

    bstTomax(root->left, a, index);
    bstTomax(root->right, a, index);
    root->data = a[index++];
}

void convertToMaxHeapUtil(Node* root) {
    int index = 0;
    vector<int> ans;

    // Perform in-order traversal and store elements in the vector
    inorder(root, ans);

    // Convert the BST to a max heap
    bstTomax(root, ans, index);
}

// Function to print in-order traversal of the tree
void printInorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Example usage
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "BST (before conversion to max heap): ";
    printInorder(root);
    cout << endl;

    // Convert the BST to a max heap
    convertToMaxHeapUtil(root);

    cout << "Max Heap (after conversion): ";
    printInorder(root);
    cout << endl;

    return 0;
}
