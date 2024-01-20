#include <iostream>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isMaxorder(struct Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (root->right == NULL) {
        return (root->left->data < root->data);
    } else {
        bool left = isMaxorder(root->left);
        bool right = isMaxorder(root->right);

        if (left && right && (root->data > root->left->data) && (root->data > root->right->data)) {
            return true;
        } else {
            return false;
        }
    }
}

bool isCBT(struct Node* root, int index, int cnt) {
    if (root == NULL) {
        return true;
    }

    if (index >= cnt) {
        return false;
    }

    bool left = isCBT(root->left, 2 * index + 1, cnt);
    bool right = isCBT(root->right, 2 * index + 2, cnt);

    return (left && right);
}

int countNode(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}
//TC:O(N)
bool isHeap(struct Node* tree) {
    int index = 0;
    int totalCount = countNode(tree);

    if (isCBT(tree, index, totalCount) && isMaxorder(tree)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    if (isHeap(root)) {
        cout << "The tree is a heap." << endl;
    } else {
        cout << "The tree is not a heap." << endl;
    }

    return 0;
}
