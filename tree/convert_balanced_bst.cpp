
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
void inorder(Node* root,vector<int>&inorderVal)
{
if(root != NULL)
{
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}
}
Node* inorderTOBst(int s,int e,vector<int>&inorderVal)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = s+(e-s)/2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderTOBst(s,mid-1,inorderVal);
    root->right = inorderTOBst(mid+1,e,inorderVal);
    return root;
}
Node* balancedBst(Node* root) {
    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderTOBst(0,inorderVal.size()-1,inorderVal);
}

void preorder(Node* root)
{
if(root != NULL)
{
    if(root->data !=-1)
    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}
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
    cout<<"before \n";
   preorder(root);
   cout<<endl;
   root = balancedBst(root);
     cout<<"after \n";
   preorder(root);
}
