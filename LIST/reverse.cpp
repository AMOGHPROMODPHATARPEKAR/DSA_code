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
void reverse(node *&start)
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
    start = prev;
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

    reverse(start);
    print(start);
}