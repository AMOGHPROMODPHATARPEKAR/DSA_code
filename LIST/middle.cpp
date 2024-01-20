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
int getLength(node *start)
{
    int len = 0;
    while (start != NULL)
    {
        len++;
        start = start->next;
    }
    return len;
}
void middle2(node *start)//pro noob
{
    if (start == NULL || start->next == NULL)
        cout <<"middle "<< start->data << endl;
    else
    {
        node *slow = start;
        node *fast = start->next;
        while (fast != NULL)
        {
            fast=fast->next;
            if(fast != NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
        }
        cout<<"middle "<<slow->data<<endl;
    }
}
void middle(node *&start)
{
    int len = getLength(start);
    node *temp = start;
    int ans = len / 2;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    cout <<"middle "<< temp->data << endl;
}
int main()
{
    node *n1 = new node(67);
    node *start = n1;
    insert_begin(start, 20);
    insert_begin(start, 30);
    // print(start);
    insert_end(start, 50);
    insert_end(start, 80);
     print(start);

    middle(start);
    middle2(start);
}