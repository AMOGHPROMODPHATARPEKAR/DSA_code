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
void solve(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    // to print or store first element
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{

    node *root = NULL;

    // creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
    cout << "Left View  \n";
    vector<int> ans = leftView(root);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}