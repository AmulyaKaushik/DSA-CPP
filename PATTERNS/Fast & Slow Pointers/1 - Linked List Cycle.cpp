#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        // Slow pointer moves one step at a time
        ListNode* slow = head;

        // Fast pointer moves two steps at a time
        ListNode* fast = head;

        // Continue while fast pointer can move forward
        while (fast != nullptr && fast->next != nullptr) {

            // Move slow pointer by one step
            slow = slow->next;

            // Move fast pointer by two steps
            fast = fast->next->next;

            // If both pointers meet, a cycle exists
            if (slow == fast)
                return true;
        }

        // If fast reaches the end, there is no cycle
        return false;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    head->next->next->next->next = head->next;

    Solution obj;

    bool result = obj.hasCycle(head);

    cout << "Cycle present: " << (result ? "Yes" : "No") << endl;

    return 0;
}