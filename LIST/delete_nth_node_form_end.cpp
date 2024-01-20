int getLength(ListNode *start)
{
    int len = 0;
    while (start != NULL)
    {
        len++;
        start = start->next;
    }
    return len;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
            return NULL;
        }
        int len=getLength(head);
        ListNode* temp=head;
        ListNode* prev=NULL;
        int cnt=0;
        int del=len-n;

        if (del == 0) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
        while(cnt< del && temp!=NULL)
        {
       cnt++;
       prev=temp;
       temp=temp->next;
        }
        if(temp != NULL){
        prev->next=temp->next;
        delete temp;
      }
        return head;
    }
//optimal O(n) sc-O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }