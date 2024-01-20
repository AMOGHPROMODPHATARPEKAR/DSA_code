#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
// TC:O(Nlogn) N-total linked list
Node* mergeKLists(vector<Node*>& listArray) {
    priority_queue<Node*, vector<Node*>, compare> minheap;

    int k = listArray.size();
    if (k == 0) {
        return NULL;
    }

    // Step 1: Push all heads into the min heap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minheap.push(listArray[i]);
        }
    }

    // Step 2: Merge lists using min heap
    Node* head = NULL;
    Node* tail = NULL;

    while (!minheap.empty()) {
        Node* temp = minheap.top();
        minheap.pop();

        if (temp->next != NULL) {
            minheap.push(temp->next);
        }

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage
    vector<Node*> listArray;

    // Creating linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    // Adding linked lists to the array
    listArray.push_back(list1);
    listArray.push_back(list2);
    listArray.push_back(list3);

    // Merging and printing the result
    Node* mergedList = mergeKLists(listArray);
    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
