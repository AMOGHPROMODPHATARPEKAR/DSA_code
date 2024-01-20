

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
void inorder(Node *root, vector<int> &inorderVal)
{
    if (root != NULL)
    {
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->data);
        inorder(root->right, inorderVal);
    }
}
Node *inorderTOBst(int s, int e, vector<int> &inorderVal)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    Node *root = new Node(inorderVal[mid]);
    root->left = inorderTOBst(s, mid - 1, inorderVal);
    root->right = inorderTOBst(mid + 1, e, inorderVal);
    return root;
}

vector<int> mergearr(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i++];
    }
    while (j < b.size())
    {
        ans[k++] = b[j++];
    }
    return ans;
}
Node *mergeBST(Node *root1, Node *root2)
{
    // step1 store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergearray = mergearr(bst1, bst2);
    int s = 0;
    int e = mergearray.size() - 1;
    return inorderTOBst(s, e, mergearray);
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
void preorder(Node *root)
{
    if (root != NULL)
    {
        if (root->data != -1)
            cout << root->data << " ";

        preorder(root->left);
        preorder(root->right);
    }
}
// optimised soln with SC O(h1+h2)

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    input(root1);
    input(root2);
    cout << " BST 1 \n";
    preorder(root1);
    cout << endl;
    cout << " BST 2 \n";
    preorder(root2);
    cout << endl;
    Node *root = mergeBST(root1, root2);
    cout << "after merging \n";
    preorder(root);
}
