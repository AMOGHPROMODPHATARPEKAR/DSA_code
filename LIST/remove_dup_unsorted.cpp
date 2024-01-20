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
void unique(node *start)
{
    if (start == NULL)
        return;

    node *cur = start;
    while (cur != NULL)
    {
        node *prev = cur;
        node *temp = cur->next;
        while (temp != NULL && prev != NULL)
        {
            if (temp->data == cur->data)
            {
                node *todel = temp;
                prev->next = temp->next;
                temp = temp->next;
                // prev = temp;
                delete todel;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        cur = cur->next;
    }
} // tc o(n2)

void remove_dup(node *start) // map O(n)
{
    node *cur = start;
    node *prev = NULL;
    map<int, bool> visited;
    while (cur != NULL)
    {
        if(visited[cur->data]==true)
        {
            node* todelete =cur;
            prev->next = cur->next;
            cur=cur->next;
            delete todelete;
            
        }
        else{
            visited[cur->data]=true;
            prev=cur;
            cur=cur->next;
        }
    }
}
int main()
{
    node *n1 = new node(10);
    cout << n1->data << endl;
    node *start = n1;
    insert_begin(start, 20);
    insert_begin(start, 10);
    print(start);
    insert_end(start, 50);
    print(start);
    insert_at_pos(start, 3, 50);
    print(start);
    remove_dup(start);
    print(start);
}