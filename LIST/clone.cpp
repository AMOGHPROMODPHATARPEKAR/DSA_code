 #include<bits/stdc++.h>
 using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node* arb;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};

 void insert_at_tail(Node *&head, Node *&tail ,int data)
{     Node *newnode = new Node(data);
    if(head == NULL)
    {
        head=newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
 Node *copyList(Node *head)
    {
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        
        Node* temp = head;
         
         while(temp != NULL)
         {
             insert_at_tail(clonehead,clonetail,temp->data);
             temp=temp->next;
         }
         
         //create a map
         
         unordered_map<Node*,Node*>otn;
         
         temp = head;//original
         Node* temp2=clonehead;//clone
         
         while(temp != NULL)
         {
             otn[temp] = temp2;
             temp=temp->next;
             temp2 = temp2->next;
         }
         
         temp = head;
         temp2=clonehead;
           while(temp != NULL)
         {
             temp2->arb = otn[temp->arb];
             temp=temp->next;
             temp2 = temp2->next;
         }
         return clonehead;
    }
    
    //tc - O(n) SC O(n)
    //approach2.......................................
       class Solution
{
    public:
    void insert_at_tail(Node *&head, Node *&tail ,int data)
{     Node *newnode = new Node(data);
    if(head == NULL)
    {
        head=newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
    Node *copyList(Node *head)
    {
        //step1 create clonelsit
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        
        Node* temp = head;
         
         while(temp != NULL)
         {
             insert_at_tail(clonehead,clonetail,temp->data);
             temp=temp->next;
         }
         
         //step2 add clone in bet orginal
         Node *original = head;
         Node *clonenode = clonehead;
         
         while(original != NULL && clonenode != NULL)
         {
             Node*next = original->next;
             original->next = clonenode;
             original = next;
             next = clonenode->next;
             clonenode->next = original;
             clonenode = next;
         }
         //step3 random pointer copy
         temp = head;
         
         while(temp != NULL)
         {
             if(temp->next != NULL)
             {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
             }
             temp= temp->next->next;
         }
         
         //step4 revert the changes of step2
         original = head;
         clonenode = clonehead;
         
          while(original != NULL && clonenode != NULL)
         {
             original->next = clonenode->next;
             original = original->next;
             
             if(original!= NULL)
             {
                 clonenode->next = original->next;
             }
             clonenode= clonenode->next;
         }
         
         return clonehead;
    }

};