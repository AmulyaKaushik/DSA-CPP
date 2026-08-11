#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        // Slow pointer moves one step at a time
        ListNode* slow = head;

        // Fast pointer moves two steps at a time
        ListNode* fast = head;

        // Find whether a cycle exists
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {

                // Start one pointer from the head
                ListNode* entry = head;

                // Move both pointers one step at a time
                // until they meet at the cycle's starting node
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                // Return the node where the cycle begins
                return entry;
            }
        }

        // No cycle exists
        return nullptr;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    head->next->next->next->next = head->next;

    Solution obj;

    ListNode* result = obj.detectCycle(head);

    if (result != nullptr)
        cout << "Cycle starts at node: " << result->val << endl;
    else
        cout << "No cycle found" << endl;

    return 0;
}