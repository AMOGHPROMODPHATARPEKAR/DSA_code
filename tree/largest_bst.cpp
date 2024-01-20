#include <bits/stdc++.h>
using namespace std;
class info
{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertToBst(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    if (data > root->data)
    {
        insertToBst(root->right, data);
    }
    else
    {
        insertToBst(root->left, data);
    }
}

void input(Node *&root)
{
    cout << "enter data to create BST " << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        insertToBst(root, data);
        cin >> data;
    }
}
info solve(Node* root,int &ans)
{
    if(root == NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info curNode;

    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data,right.maxi);
    curNode.mini = min(root->data,left.mini);

    if(left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini ))
    { 
     curNode.isbst=true;
    }
    else
    {
        curNode.isbst =false;
    }
    //update ans

    if(curNode.isbst)
    {
        ans = max(ans,curNode.size);
    }
return curNode;
}
int largestBST(Node * root){
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}
int main()
{
    Node *root1 = NULL;
    
    input(root1);

    cout<<"count is "<<largestBST(root1);
}
