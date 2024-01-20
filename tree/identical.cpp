
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
    bool isIdentical(node *r1, node *r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if(r1 == NULL && r2 != NULL)
        {
            return false;
        }
          if(r1 != NULL && r2 == NULL)
        {
            return false;
        }
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        
        bool value = r1->data == r2->data;
        
        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
int main() {

    node* root = NULL;

   
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
  cout<<"Identical   "<<boolalpha<<isIdentical(root,root)<<endl;
  

    return 0;
}