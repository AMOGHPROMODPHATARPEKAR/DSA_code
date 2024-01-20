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
bool searchInBST(Node* root,int x)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == x)
    {
        return true;
    }
    if(root->data > x)
    {
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }
    
    }
    bool IsearchBST(Node* root,int x){
    Node *temp = root;

   while(temp != NULL)
   {
       if(temp->data == x)
       {
           return true;;
       }
       if(temp->data > x)
       {
           temp = temp->left;
       }
       else
       {
           temp =temp->right;
       }
   }
   return false;
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
    int x;
    cout<<"enter element to search\n";
    cin>>x;
   if(IsearchBST(root,x))
   {
cout<<"found ";
   }
   else{
    cout<<"not found";
   }
}