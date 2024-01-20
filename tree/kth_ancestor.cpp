
    
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
node* solve(node*root,int &k,int Node)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == Node)
    {
        return root;
    }
    node* leftAns =solve(root->left,k,Node);
    node* rightAns =solve(root->right,k,Node);
    
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
        if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
// your task is to complete this function
int kthAncestor(node *root, int k, int Node)
{ 
    node *ans = solve(root,k,Node);
    if(ans == NULL||root->data == Node)
    {
        return -1;
    }
    else
    return ans->data;
    
}
int main()
{

    node *root = NULL;

    // creating a Tree
    root = buildTree(root);
    // 1 3 7  -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout<<"ancestor is "<<kthAncestor(root,3,7);
    return 0;
}