
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
int height(node* node){
        if(node == NULL)
        {
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        int ans = 1 + max(left,right);
        return ans;
    }

    // Function to return the diameter of a Binary Tree.
    bool isBalanced(node *root)
    {
        if(root == NULL)
        {
            return true;
        }
        
        bool op1 = isBalanced(root->left);
        bool op2 = isBalanced(root->right);
        bool op3 = abs(height(root->left)- height(root->right))<=1;
        if(op1 && op2 &&op3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //optimised O(n)
    pair<bool,int> balanced_fast(node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int>left = balanced_fast(root->left);
    pair<bool,int>right = balanced_fast(root->right);
    
    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 =abs(left.second - right.second)<=1;
    
    pair<bool,int>ans;
    ans.second = max(left.second, right.second)+1;
            
        if(op1 && op2 &&op3)
        {
            ans.first = true;
        }
        else
        {
            ans.first= false;
        }
    return ans; 
    
}
int main() {

    node* root = NULL;

   
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
  cout<<"balanced  "<<boolalpha<<isBalanced(root)<<endl;
  cout<<"balanced  fast  "<<boolalpha<<balanced_fast(root).first<<endl;

    return 0;
}