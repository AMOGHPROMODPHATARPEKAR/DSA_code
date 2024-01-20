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
vector <int> zigZagTraversal(node* root)
    {
    	
    	vector<int>result;
    	if(root == NULL)
    	{
    	    return result;
    	}
    	queue<node*>q;
    	q.push(root);
    	
    	bool leftToright =true;
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int>ans(size);
    	    
    	    for(int i=0;i<size;i++)
    	    {
    	        node* temp = q.front();
    	        q.pop();
    	        
    	        int index = leftToright ? i:size-i-1;
    	        ans[index]= temp->data;
    	        
    	        if(temp->left)
    	        q.push(temp->left);
    	        
    	        if(temp->right)
    	        q.push(temp->right);
    	    }
    	    //change direction
    	    leftToright = !leftToright;
    	    
    	    for(auto i:ans)
    	    {
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
    void zig_zaq_op(node* root) {
    queue<node*> q;
    q.push(root);
    
bool leftToRigth = true;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
     cout << temp -> data << " ";
            if(leftToRigth)
            {
                leftToRigth = !leftToRigth;
                 if(temp ->right) {
                q.push(temp ->right);
        }
        if(temp ->left) {
                q.push(temp ->left);
            }
           
            }
        else{
             if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            
    }
    
    }
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
    cout<<"Zig-Zag \n";
  vector<int>ans = zigZagTraversal(root);
  for(auto i: ans)
  cout<<i<<" ";
  cout<<"zig zag op\n";
  zig_zaq_op(root);
    return 0;
}