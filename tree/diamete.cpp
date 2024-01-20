
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
    int diameter(node* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3= height(root->left)+ height(root->right)+1;
        
        int ans = max(op1,max(op2,op3));
        return ans;
    }
    //optimised O(n)
    pair<int,int> diameter_fast(node* root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int>left = diameter_fast(root->left);
    pair<int,int>right = diameter_fast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 =left.second + right.second +1;
    
    pair<int,int>ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second, right.second)+1;
    
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
  cout<<"diameter is "<<diameter(root)<<endl;
  cout<<"diameter  fast is "<<diameter_fast(root).first<<endl;

    return 0;
}