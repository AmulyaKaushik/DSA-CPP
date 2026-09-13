#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // curr points to the node we are currently reversing
        ListNode* curr = head;

        // prev stores the previous node
        // It becomes the new next pointer of curr
        ListNode* prev = nullptr;

        while(curr != nullptr) {

            // Store the next node before changing curr->next
            ListNode* next = curr->next;

            // Reverse the direction of the current node
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = next;
        }

        // prev is now the new head of the reversed list
        return prev;
    }
};

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    cout << "Original list: ";
    printList(head);

    head = obj.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}