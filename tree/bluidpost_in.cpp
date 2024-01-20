#include <bits/stdc++.h>
using namespace std;

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
    int findpos(int in[],int ele,int n)
{
    for(int i=0;i<n;i++)
    {
        if(in[i] == ele)
        return i;
    }
    return -1;
}
Node* solve(int in[],int pre[], int n,int &index,int inoderStart,int inorderEnd)
{ 
    if(index <0 || inoderStart > inorderEnd)
    {
        return NULL;
    }
    int ele = pre[index--];
    Node* root = new Node(ele);
    int pos = findpos(in,ele,n);
    
    //recursive calls
    root->right = solve(in,pre,n,index,pos+1,inorderEnd);
    root->left = solve(in,pre,n,index,inoderStart,pos-1);
    
    return root;
}
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex =n-1;
        Node* ans = solve(in,pre,n,preorderIndex,0,n-1);
        return ans;
    }
void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{

    Node *root = NULL;

    int in[] = {7, 3, 11, 1, 17, 8, 18};
    int post[] = {7,11,3,17,18,8,1};
    root = buildTree(in, post, 7);
    cout << "pre order  " << endl;
    preorder(root);

    return 0;
}