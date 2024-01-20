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
 pair<bool,int> isSumFast(node *root)
    {
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
        return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
          pair<bool,int> p = make_pair(true,root->data);
        return p;
        }
        
        pair<bool,int>left = isSumFast(root->left);
         pair<bool,int>right = isSumFast(root->right);
  
  bool leftans = left.first;
  bool rightans = right.first;
  
  bool cond = root->data == (left.second +right.second);
  pair<bool,int>ans;
  if(leftans && rightans && cond)
  {
      ans.first=true;
      ans.second = root->data + left.second +right.second;
  }
  else
  {
      ans.first = false;
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
  cout<<"is sum balanced  "<<boolalpha<<isSumFast(root).first<<endl;


    return 0;
}