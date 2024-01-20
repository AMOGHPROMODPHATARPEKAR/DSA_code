#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_begin(node *&start, int d)
{
    node *temp = new node(d);
    start->prev = temp;
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

    temp->prev = end;
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
    if (temp->next == NULL)
    {
        insert_end(start, d);
        return;
    }
    node *insert_node = new node(d);
    temp->next->prev = insert_node;
    insert_node->next = temp->next;
    insert_node->prev = temp;
    temp->next = insert_node;
}
void delete_node(node *&start, int value)
{
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (temp == start)
            {
                start = start->next;
                start->prev = NULL;
                break;
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                break;
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                 break;
            }
        }
        temp = temp->next;
    }
    delete temp;
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
    insert_at_pos(start, 5, 15);
    print(start);
    delete_node(start, 15);
    print(start);
}