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

void insert_at_tail(node *&tail, node *cur)
{
    tail->next = cur;
    tail = cur;
}

node *merge(node *start1, node *start2)
{
    if (start1 == NULL)
    {
        return start2;
    }
    if (start2 == NULL)
    {
        return start1;
    }
    node *cur1 = start1;
    node *next1 = cur1->next;
    node *cur2 = start2;
    node *next2;
    while (next1 != NULL && cur2 != NULL)
    {
        if ((cur2->data >= cur1->data) && (cur2->data <= next1->data))
        {
            cur1->next = cur2;
            next2 = cur2->next;
            cur2->next = next1;
            cur1 = cur2;
            cur2 = next2;
        }
        else
        {
            cur1 = next1;
            next1 = next1->next;

        }
    }
    if (next1 == NULL)
            {
                cur1->next = cur2;
                return start1;
            }
            return start1;
}
node* merge_opt(node* f,node* s) {

    if(f==NULL) {

        return s;

    }

    if(s==NULL) {

        return f;

    }

    node* head=new node(-1);

    node* tmp=head;

    while(f!=NULL && s!=NULL) {

        if(f->data > s->data) {

            tmp->next = s;

            tmp = s;

            s=s->next;

        }

        else {

            tmp->next = f;

            tmp = f;

            f=f->next;

        }

    }

    while(f!=NULL) {

        tmp->next = f;

        tmp = f;

        f=f->next;

    }

    while(s!=NULL) {

        tmp->next = s;

        tmp = s;

        s=s->next;

    }

    return head->next;

}
//inplace 
node* mergeTwoLists(node* l1, node* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->data > l2->data) swap(l1,l2);

        // act as head of resultant merged list
        node* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            node* temp = NULL;

            while(l1 != NULL && l1->data <= l2->data) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            swap(l1,l2);
        }

        return res;
    }
int main()
{
    node *n1 = new node(2);
    node *start1 = n1;
    insert_begin(start1, 1);
    insert_begin(start1, 0);
    print(start1);
    node *n2 = new node(3);
    node *start2 = n2;
    insert_begin(start2, 1);
 
    insert_end(start2, 5);
    print(start2);
    node *start;
    if(start1->data <= start2->data)
     {
        start= merge_opt(start1, start2);
        }
        else{
            start = merge_opt(start2, start1);
        }
    print(start);
}