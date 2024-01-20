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

bool isBst(Node *root,int min, int max)
{
  if(root == NULL)
  {
    return true;
  }
    if(root->data >= min && root->data <= max)
    {
        bool left = isBst(root->left,min,root->data);
        bool right =  isBst(root->right,root->data,max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(Node *root) {
    return isBst(root,INT_MIN,INT8_MAX);
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
     
     if(validateBST(root))
     {
        cout<<"valid BST";
     }
     else
     {
        cout<<"Invlaid BSt";
     }
}