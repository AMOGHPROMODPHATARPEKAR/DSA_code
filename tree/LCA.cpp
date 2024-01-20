
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
    node* lca(node* root ,int n1 ,int n2 )
    {
       if(root == NULL)
       {
           return NULL;
       }
       if(root->data == n1 || root->data == n2)
       {
           return root;
       }
       node*left = lca(root->left,n1,n2);
       node*right =  lca(root->right,n1,n2);
       
       if(left != NULL && right != NULL)
       {
           return root;
       }
       else if(left != NULL && right == NULL)
       {
           return left;
       }
        else if(left == NULL && right != NULL)
       {
           return right;
       }
       else 
       return NULL;
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
    node* ans = lca(root,7,11);
    cout<<"Least common ancestor is "<<ans->data;
    return 0;
}