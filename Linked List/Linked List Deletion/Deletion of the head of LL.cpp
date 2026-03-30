#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if (head == nullptr) return nullptr; // edge case: empty list
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};

// Helper: insert at tail
void insertAtTail(ListNode* &head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Helper: print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    cout << "Before: ";
    printList(head);

    Solution sol;
    sol.deleteHead(head);

    cout << "After:  ";
    printList(head);

    return 0;
}
/*

**Output:**
```
Before: 1 -> 2 -> 3 -> 4
After:  2 -> 3 -> 4
*/