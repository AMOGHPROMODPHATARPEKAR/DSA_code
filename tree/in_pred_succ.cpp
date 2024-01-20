
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertToBst(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    if (data > root->data)
    {
        insertToBst(root->right, data);
    }
    else
    {
        insertToBst(root->left, data);
    }
}
pair<int, int> predecessorSuccessor(Node* root, int key) {
    Node* temp = root;
    int pred = -1;
    int suc = -1;

    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->left != NULL) {
                Node* leftTree = temp->left;
                while (leftTree->right != NULL) {
                    leftTree = leftTree->right;
                }
                pred = leftTree->data;
            }
            if (temp->right != NULL) {
                Node* rightTree = temp->right;
                while (rightTree->left != NULL) {
                    rightTree = rightTree->left;
                }
                suc = rightTree->data;
            }
            break;
        } else if (temp->data > key) {
            suc = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    pair<int, int> ans = make_pair(pred, suc);
    return ans;
}

int main()
{
    Node *root = NULL;

    cout << "enter data to create BST " << endl;
    int data;
    while (data != -1)
    {
        cin >> data;
        insertToBst(root, data);
    }
    pair<int,int>ans = predecessorSuccessor(root,1363318);
    cout<<ans.first<<" "<<ans.second;
}
// 6521171 5650934 9278816 899375 -1 8989449 -1 -1 -1 -1 -1 
// 9615950
// 7514254 1803722 7527727 1181548 -1 -1 -1 -1 -1 
// 1363318
