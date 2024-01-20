Node* reverseDLL(Node * head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
      Node* pre =NULL;
      Node* cur=head;
      while(head != NULL)
      {
          Node* nex = head->next;
          head->next = pre;
          head->prev =nex;
          pre = head;
          head = nex;
      }
      return pre;
    }