

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
bool twoSumInBST(Node* root, int target) {
	vector<int>inorderVal;
inorder(root,inorderVal);
    int i=0,j = inorderVal.size()-1;

    while(i<j)
    {
    int sum = inorderVal[i] + inorderVal[j];
    if(sum == target)
    {
        return true;
    }
    if(sum > target)
    {
        j--;
    }
    else{
        i++;
    }
    }
    return false;

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
   twoSumInBST(root,10) ? cout<<" sum exists" : cout<<" sum doesnt exist";
}
