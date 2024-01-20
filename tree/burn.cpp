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

Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
Node *createmap(Node *root, int target,
                map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                flag = true;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
                flag = true;
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    // step1: create a map of NodeTOparent
    map<Node *, Node *> nodeToParent;

    // setp2:find target node
    Node *targetNode = createmap(root, target, nodeToParent);

    // step3 burn the tree in min time
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
int main()
{

    Node *root = NULL;

    // creating a Tree
    root = buildTree(root);
    // 1 3 7  -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout << "MIN time  is " << minTime(root, 7);
    return 0;
}