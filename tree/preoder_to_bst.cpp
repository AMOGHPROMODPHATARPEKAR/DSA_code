
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
Node *solve(vector<int> &preorder, int &i, int mini, int maxi)
{
    if (i >= preorder.size())
    {
        return NULL;
    }
    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return nullptr;
    }

    Node *root = new Node(preorder[i++]);
    root->left = solve(preorder, i, mini, root->data);
    root->right = solve(preorder, i, root->data, maxi);
    return root;
}
Node *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, i, mini, maxi);
}
void inorder(Node* root) {
    //base case
    if(root != NULL) {
   

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
 }
}
int main()
{

    vector<int>preorder = {10,5,7,8,11};
    Node *root = preorderToBST(preorder);
inorder(root);
}
