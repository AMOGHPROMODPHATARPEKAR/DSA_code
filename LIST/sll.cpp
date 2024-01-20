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
void delete_node(node *&start, int value)
{
    node *prev = 0;
    node *cur = start;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            if (cur == start)
            {
                start = start->next;
                break;
            }

            else
            {
                prev->next=cur->next;
                cur->next=NULL;
            }
        }
        prev=cur;
        cur=cur->next;
    }
    delete cur;
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
int main()
{
    node *n1 = new node(10);
    cout << n1->data << endl;
    node *start = n1;
    insert_begin(start, 20);
    insert_begin(start, 30);
    print(start);
    insert_end(start, 50);
    print(start);
    insert_at_pos(start,3, 15);
    print(start);
    delete_node(start,50);
    print(start);
}