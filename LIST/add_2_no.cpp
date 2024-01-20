#include <iostream>
#include <map>
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
node *reverse(node *start)
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
void insert_at_tail(node *&head, node *&tail, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
node *add_opt(node *first, node *sec)
{
    int carry = 0;
    node *anshead = NULL;
    node *anstail = NULL;
    while (first != NULL || sec != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (sec != NULL)
            val2 = sec->data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insert_at_tail(anshead, anstail, digit);
        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        if (sec != NULL)
            sec = sec->next;
    }
    return anshead;
}
node *add(node *first, node *sec)
{
    int carry = 0;
    node *anshead = NULL;
    node *anstail = NULL;
    while (first != NULL && sec != NULL)
    {
        int sum = first->data + sec->data + carry;
        int digit = sum % 10;
        insert_at_tail(anshead, anstail, digit);
        carry = sum / 10;
        first = first->next;
        sec = sec->next;
    }
    while (first != NULL)
    {
        int sum = first->data + carry;
        int digit = sum % 10;
        insert_at_tail(anshead, anstail, digit);
        carry = sum / 10;
        first = first->next;
    }
    while (sec != NULL)
    {
        int sum = sec->data + carry;
        int digit = sum % 10;
        insert_at_tail(anshead, anstail, digit);
        carry = sum / 10;
        sec = sec->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insert_at_tail(anshead, anstail, digit);
        carry = sum / 10;
    }
    return anshead;
}
node *add_2(node *first, node *sec)
{
    first = reverse(first);
    sec = reverse(sec);

    node *ans = add_opt(first, sec);
    ans = reverse(ans);
    return ans;
}

int main()
{
    node *n1 = new node(2);
    node *start1 = n1;
    insert_begin(start1, 1);
    insert_begin(start1, 9);
    print(start1);
    node *n2 = new node(3);
    node *start2 = n2;
    insert_begin(start2, 1);
    insert_end(start2, 5);
    print(start2);
    node *start = add_2(start1, start2);
    cout << "answer = ";
    print(start);
}