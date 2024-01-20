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

void insertToBst(Node* &root,int data)
{
  if(root == NULL)
  {
    root = new Node(data);
    return;
  }
  if(data > root->data)
  {
    insertToBst(root->right,data);
  }
  else
  {
    insertToBst(root->left,data);
  }
}
int solve(Node* root,int &i, int k)
{
    if(root == NULL)
    {
        return -1;
    }
    //L
    int left = solve(root->left,i,k);

    if(left != -1)
    {
     return left;
    }
    //N
    i++;
    if(i==k)
    {
        return root->data;
    }
    //R
    return solve(root->right, i,k);

}
int kthSmallest(Node* root, int k) {
    int i=0;
    int ans = solve(root,i,k);
    return ans;

}

int main()
{
    Node* root = NULL;

    cout<<"enter data to create BST "<<endl;
    int data;
    while(data!=-1)
    {
        cin>>data;
        insertToBst(root,data);
    }
   cout<<"Kth min element is "<<kthSmallest(root,2);
}