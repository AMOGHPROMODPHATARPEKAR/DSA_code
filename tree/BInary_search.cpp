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
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
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
void inorder(Node* root) {
    //base case
    if(root != NULL ) {
   
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
 }
}
Node* minBst(Node*root)
{
    Node*temp = root;

    if(temp->left != NULL)
    {
        temp= temp->left;
    }
    return temp;
}
Node* maxBst(Node*root)
{
    Node*temp = root;

    if(temp->right != NULL)
    {
        temp= temp->right;
    }
    return temp;
}

Node* delete_bst(Node*root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data == val)
    {
        //0 child
     if(root->left == NULL && root->right==NULL)
     {
        delete root;
        return NULL;
     } //1 child
     else if (root->left != NULL &&root->right == NULL)
     {
        Node*temp = root->left;
        delete root;
        return temp;
     }
     else if(root->left == NULL && root->right != NULL)
     {
       Node*temp = root->right;
        delete root;
        return temp;
     }//2 child
     else{
        int maxi = maxBst(root->left)->data;
        root->data = maxi;
        root->left = delete_bst(root->left,maxi);
        return root;
     }
    }
    else if(root->data > val)
    {
        root->left = delete_bst(root->left,val);
    }
    else
    {
        root->right = delete_bst(root->right,val);
    }
}
int main()
{
    Node* root = NULL;

    cout<<"enter data to create BST "<<endl;
    int data;
    cin>>data;
    while(data!=-1)
    {
        
        insertToBst(root,data);
        cin>>data;
    }
    cout<<"Tree is \n";
    inorder(root);
     cout<<endl<<"min value is "<<minBst(root)->data<<endl;
     cout<<"max value is "<<maxBst(root)->data<<endl;
     root = delete_bst(root,50);
     inorder(root);
}