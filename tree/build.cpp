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
    if(index >= n || inoderStart > inorderEnd)
    {
        return NULL;
    }
    int ele = pre[index++];
    Node* root = new Node(ele);
    int pos = findpos(in,ele,n);
    
    //recursive calls
    
    root->left = solve(in,pre,n,index,inoderStart,pos-1);
    root->right = solve(in,pre,n,index,pos+1,inorderEnd);
    
    return root;
}
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex =0;
        Node* ans = solve(in,pre,n,preorderIndex,0,n-1);
        return ans;
    }
    void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
    int main()
{

    Node *root = NULL;

int in[]={7 ,3 ,11, 1 ,17 ,3 ,18};
int pre[]={1, 3 ,7,11, 3, 17 ,18};
root =buildTree(in,pre,7);
    cout << "post  " << endl;
    postorder(root);

    return 0;
}