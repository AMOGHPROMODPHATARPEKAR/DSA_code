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
void sort_01(node *start)
{
    int zc=0;
    int oc=0;
    int tc=0;
    
    node* temp=start;
    while (temp != NULL)
    {
        if(temp->data == 0)
        {
            zc++;
        }
        else if(temp->data == 1)
        {
            oc++;
        }
        else{
            tc++;
        }
        temp=temp->next;
    }
    temp =start;
    while (temp != NULL)
    {
        if(zc !=0)
        {
            temp->data = 0;
            zc--;
        }
        else if(oc != 0)
        {
            temp->data =1;
            oc--;
        }
        else if(tc != 0)
        {
            temp->data =2;
            tc--;
        }

        temp= temp->next;
    }
    
}
void insert_at_tail(node* &tail,node*cur)
{
    tail->next =cur;
    tail =cur;
}
void sort_0_1(node *&start)
{
   node* zerohead = new node(-1);
   node* zerotail =zerohead;
   node* onehead = new node(-1);
   node* onetail =onehead;
   node* twohead = new node(-1);
   node* twotail =twohead;

   node*cur =start;
   while (cur != NULL)
   {
    int value = cur->data;
    if(value == 0)
    {
        insert_at_tail(zerotail,cur);
    }
    else if(value == 1)
    {
        insert_at_tail(onetail,cur);
    }
    else if(value == 2) 
    {
        insert_at_tail(twotail,cur);
    }
    cur =cur->next;
   }
   //merge list
   if(onehead->next != NULL)
   {
    zerotail->next = onehead->next;
    onetail->next=twohead->next;
   }
   else
   {
    zerotail->next = twohead->next;
   }
   
   twotail->next =NULL;

   start = zerohead->next;
   delete zerohead;
   delete onehead;
   delete twohead;
   
}
int main()
{
    node *n1 = new node(0);
    cout << n1->data << endl;
    node *start = n1;
    insert_begin(start, 2);
    insert_begin(start, 1);
    print(start);
    insert_end(start, 0);
    print(start);
    insert_at_pos(start, 3, 1);
    print(start);
    sort_0_1(start);
    print(start);
    
}