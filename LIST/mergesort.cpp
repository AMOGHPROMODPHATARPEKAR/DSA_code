#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_begin(node *&start, int d)
{
    node *temp = new node(d);
    temp->next = start;
    start = temp;
}
void insert_end(node *&start, int d)
{
    node *temp = new node(d);
    node *end = start;
    while (end->next != NULL)
    {
        end = end->next;
    }
    end->next = temp;
}
void insert_at_pos(node *&start, int pos, int d)
{
    if (pos == 1)
    {
        insert_begin(start, d);
        return;
    }
    node *temp = start;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    node *insert_node = new node(d);
    insert_node->next = temp->next;
    temp->next = insert_node;
}

void print(node *&start)
{
    node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *find_mid(node *start) // pro noob
{

    node *slow = start;
    node *fast = start->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
node *mergesort(node *start)
{
    if (start == NULL || start->next == NULL)
    {
        return start;
    }
    node *mid = find_mid(start);
    node *left = start;
    node *right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    node *result = merge(left, right);
    return result;
}

int main()
{
    node *n1 = new node(10);
    node *start = n1;
    insert_begin(start, 20);
    insert_begin(start, 30);
    // insert_begin(start, 4);
    insert_end(start, 50);
    insert_at_pos(start, 3, 15);
    print(start);
    node *res = mergesort(start);
    print(res);
}