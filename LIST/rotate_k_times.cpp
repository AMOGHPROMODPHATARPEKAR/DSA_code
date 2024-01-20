#include <iostream>

namespace LinkedListNamespace {

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    int length(ListNode* head) {
        if (head == nullptr) {
            return 0;
        }
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    void rotate(ListNode*& head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        temp->next = head;
        head = temp;
        prev->next = nullptr;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if (len == 0 || len == 1) {
            return head;
        }
        if (k % len == 0) {
            return head;
        }
        k = k % len;
        for (int i = 0; i < k; i++) {
            rotate(head);
        }
        return head;
    }

}  // namespace LinkedListNamespace

int main() {
    using namespace LinkedListNamespace;
    
    // Example Usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    ListNode* rotatedHead = rotateRight(head, k);

    // Displaying the rotated linked list
    ListNode* current = rotatedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
