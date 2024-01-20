
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
    void solve(node*root,int sum,int &maxsum,int len,int &maxlen)
    {
        if(root == NULL)
        {
            if(len>maxlen)
            {
                maxlen =len;
                maxsum =sum;
            }
            else if(len == maxlen)
            {
                maxsum = max(sum,maxsum);
            }
            return ;
        }
        sum = sum+ root->data;
        
        solve(root->left,sum,maxsum,len+1,maxlen);
        solve(root->right,sum,maxsum,len+1,maxlen);
    }
    
    int sumOfLongRootToLeafPath(node *root)
    {
       int len = 0;
       int maxlen = 0;
       
       int sum =0;
       int maxsum = INT_MIN;
       
       solve(root,sum,maxsum,len,maxlen);
       return maxsum;
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
    cout<<"su of longest path = "<<sumOfLongRootToLeafPath(root);
    return 0;
}