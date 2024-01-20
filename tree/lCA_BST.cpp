
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
Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
   if(root ==NULL)
   {
       return root;
   }
   if(root->data <P->data && root->data < Q->data)
   {
       return LCAinaBST(root->right,P,Q);
   }
   if(root->data >P->data && root->data > Q->data)
   {
       return LCAinaBST(root->left,P,Q);
   }
   return root;
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
    cout<<"LCA is "<<LCAinaBST(root,root->left->left,root->left->right)->data;
}
