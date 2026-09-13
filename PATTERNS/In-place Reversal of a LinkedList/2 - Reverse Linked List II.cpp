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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If the list is empty or only one node needs to be reversed
        if(!head || left == right)
            return head;

        ListNode* before = nullptr;
        ListNode* temp = head;
        int pos = 1;

        // Move temp to the left position
        // before points to the node just before the reversal starts
        while(pos < left){
            before = temp;
            temp = temp->next;
            pos++;
        }

        // Number of nodes that need to be reversed
        int times = right - left + 1;

        ListNode* prev = nullptr;
        ListNode* curr = temp;

        // Reverse the nodes between left and right
        while(times--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // temp is now the last node of the reversed portion
        // Connect it to the remaining part of the list
        temp->next = curr;

        if(before){

            // Connect the node before the reversed portion
            // to the new first node of the reversed portion
            before->next = prev;

            return head;
        }

        // If left was 1, prev becomes the new head
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

    int left = 2;
    int right = 4;

    Solution obj;

    cout << "Original list: ";
    printList(head);

    head = obj.reverseBetween(head, left, right);

    cout << "After reversing: ";
    printList(head);

    return 0;
}