

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
void convertintoSortedDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    convertintoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;

    convertintoSortedDLL(root->left, head);
}
Node *mergelinkedlist(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
             tail ->right = head1;
             head1->left= tail;
             tail = head1;
             head1=head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
            tail ->right = head2;
             head2->left= tail;
             tail = head2;
             head2=head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail ->right = head1;
             head1->left= tail;
             tail = head1;
             head1=head1->right;
    }
    while (head2 != NULL)
    {
        tail ->right = head2;
             head2->left= tail;
             tail = head2;
             head2=head2->right;
    }
    return head;
}
int countNodes(Node* head)
{
    int cnt=0;
    Node*temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
Node* sortedLLtoBST(Node * &head,int n)
{
    if(n<=0 || head == NULL)
    {
        return NULL;
    }
    Node* left = sortedLLtoBST(head,n/2);
    
    Node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLtoBST(head,n-n/2-1);
    return root;
}
Node* mergeBST(Node*root1,Node*root2)
{
//step1 conver to sorte DLL in place
    Node* head1 = NULL;
    convertintoSortedDLL(root1,head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertintoSortedDLL(root2,head2);
    head2->left = NULL;

    //step2 merge sorted linked list 

    Node * head = mergelinkedlist(head1,head2);

    //step3 convert sll to BSt

    return sortedLLtoBST(head,countNodes(head));
}
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
