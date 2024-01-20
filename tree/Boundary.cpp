#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
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
   void traverseLeft(node* root,vector<int>&ans)
   {
       if(root == NULL || (root->left == NULL && root->right == NULL))
       {
           return;
       }
       ans.push_back(root->data);
       
       if(root->left)
       {
           traverseLeft(root->left,ans);
       }
       else
       {
           traverseLeft(root->right,ans);
       }
   }
   
      void traverseLeaf(node* root,vector<int>&ans)
   {
       if(root == NULL ) 
       {
           return;
       }
       if(root->left == NULL && root->right == NULL)
       {
           ans.push_back(root->data);
           return;
       }
       
       traverseLeaf(root->left,ans);
       traverseLeaf(root->right,ans);
   }
   void traverseRight(node* root,vector<int>&ans)
   {
       if(root == NULL || (root->left == NULL && root->right == NULL))
       {
           return;
       }
      
       
       if(root->right)
       {
           traverseRight(root->right,ans);
       }
       else
       {
           traverseRight(root->left,ans);
       }
        ans.push_back(root->data);
   }
    vector <int> boundary(node *root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        //traverse left part
        traverseLeft(root->left,ans);
        //traverse leaf
        //left subtree
        traverseLeaf(root->left,ans);
        //right subtree
        traverseLeaf(root->right,ans);
        
        //traverse right tree
        traverseRight(root->right,ans);
        
        return ans;
    }
int main() {

    node* root = NULL;

   
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    levelOrderTraversal(root);
    cout<<"boundary  \n";
  vector<int>ans = boundary(root);
  for(auto i: ans)
  cout<<i<<" ";
    return 0;
}