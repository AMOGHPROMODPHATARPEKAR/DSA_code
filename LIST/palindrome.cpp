#include <iostream>
#include <vector>
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
bool isPal(node *start) // TC O(n) SC O(n)
{
    vector<int> ans;
    node *temp = start;
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    int n = ans.size();
    int s = 0;
    int e = n - 1;
    while (s <e)
    {
        if (ans[s] != ans[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}
node *getmid(node *start)
{
    if (start == NULL || start->next == NULL)
        return start;
    else
    {
        node *slow = start;
        node *fast = start->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
}
node * reverse(node *start)
{
    node *prev = NULL;
    node *cur = start;
    node *forward = NULL;
    while (cur != NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}
bool ispal(node *start)
{
    if (start->next == NULL)
        return true;

        node* middle = getmid(start);
        node *temp = middle->next;
        middle->next = reverse(temp);

        node*head1 = start;
        node* head2 = middle->next;
        while (head2 != NULL)
        {
            if(head1->data != head2->data)
            {
                return 0;
            }
            head1= head1->next;
            head2= head2->next;
        }
        //convert back
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
}
int main()
{
    node *n1 = new node(1);
    node *start = n1;
    insert_begin(start, 2);
    insert_begin(start, 1);
    print(start);
    print(start);
    insert_at_pos(start, 3, 2);
    print(start);
    if (isPal(start))
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not a palindrome";
    }
}