
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
void inorder(Node* root,vector<Node*>&inorderVal)
{
if(root != NULL)
{
    inorder(root->left,inorderVal);
    inorderVal.push_back(root);
    inorder(root->right,inorderVal);
}
}

Node* flatten(Node* root)
{
     vector<Node*>inorderVal;
     inorder(root, inorderVal);
     int i;
     for(i=0;i<inorderVal.size()-1;i++)
     { 
         inorderVal[i]->left = NULL;
         inorderVal[i]->right = inorderVal[i+1];   
     }
     inorderVal[i]->left = NULL;
     inorderVal[i]->right = NULL;
     return inorderVal[0];
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
   Node*ans= flatten(root);
   while (ans != NULL)
   {
    if(ans->data != -1)
    cout<<ans->data<<" ";
    
    ans = ans->right;
   }
   
   
}
