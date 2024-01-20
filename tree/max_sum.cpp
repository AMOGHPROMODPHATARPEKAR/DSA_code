
    
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
 pair<int,int> solve(node* root)
  {
      if(root == NULL)
      {
          pair<int,int>p =make_pair(0,0);
          return p;
      }
      pair<int,int>left = solve(root->left);
      pair<int,int>right = solve(root->right);
      
      pair<int,int>res;
      
      res.first = root->data + left.second + right.second;
      res.second = max(left.first,left.second) + max(right.first,right.second);
      
      return res;
      
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(node *root) 
    {
      pair<int,int>ans = solve(root);
      return max(ans.first,ans.second);
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

    cout<<"MAX sum  is "<<getMaxSum(root);
    return 0;
}