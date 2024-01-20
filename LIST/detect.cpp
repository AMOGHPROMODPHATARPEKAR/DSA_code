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
node* detect(node *start)
{
    if (start == NULL)
        return NULL;

    map<node *, bool> visited;
    node *temp = start;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return temp;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return NULL;
}
bool floyd(node* start)
{
    if(start == NULL)
    return false;

    node* slow = start;
    node* fast= start;
    while (slow!=NULL &&fast!=NULL && fast->next != NULL)
    {
       slow =slow->next;
       fast= fast->next->next;

       if(slow == fast)
       {
        return true;
       }
    }
    return false;
    
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
    if (floyd(start))
    {
        cout << "circular lsit" << endl;
    }
    else
    {
        cout << " not circular lsit" << endl;
    }
    node* temp = detect(start);
    cout<<temp->data;
}