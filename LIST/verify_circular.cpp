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
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
    }
    else
    {
        node *end = start;
        while (end->next != start)
        {
            end = end->next;
        }
        temp->next = start;
        start = temp;
        end->next = start;
    }
}
void insert_end(node *&start, int d)
{
    node *temp = new node(d);
    node *end = start;
    while (end->next != start)
    {
        end = end->next;
    }
    end->next = temp;
    temp->next = start;
}

void print(node *&start)
{
    node *temp = start;
    while (temp->next != start)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}
bool isCircular(node *start)
{
    if (start == NULL)
        return NULL;

    node *temp = start->next;
    while (temp != NULL && temp != start)
    {
        temp = temp->next;
    }

    if(temp == start)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    node *start = NULL;
    insert_begin(start, 10);
    insert_begin(start, 20);
    insert_begin(start, 30);
    print(start);
    insert_end(start, 50);
    print(start);
    if(isCircular(start))
    {
        cout<<"circular lsit"<<endl;
    }
    else{
        cout<<" not circular lsit"<<endl;
    }
}