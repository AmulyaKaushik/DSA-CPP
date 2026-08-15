#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Handle empty list or single-node list
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // Slow pointer moves one step at a time
        ListNode* slow = head;

        // Fast pointer moves two steps at a time
        ListNode* fast = head;

        // Find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Find the node before the middle node
        ListNode* temp = head;

        while (temp->next != slow) {
            temp = temp->next;
        }

        // Remove the middle node from the list
        temp->next = slow->next;

        // Free the memory of the deleted node
        delete slow;

        // Return the updated head
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "List after deleting middle: ";

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}