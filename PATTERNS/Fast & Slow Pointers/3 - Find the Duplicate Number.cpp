#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Initialize slow and fast pointers
        int slow = 0;
        int fast = 0;

        // Find the meeting point inside the cycle
        while (true) {

            // Slow moves one step
            slow = nums[slow];

            // Fast moves two steps
            fast = nums[fast];
            fast = nums[fast];

            // If both pointers meet, a cycle exists
            if (slow == fast) {

                // Reset slow to the beginning
                slow = 0;

                // Move both pointers one step at a time
                // until they meet at the duplicate number
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }

                // The meeting point is the duplicate number
                return slow;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution obj;

    int result = obj.findDuplicate(nums);

    cout << "Duplicate number: " << result << endl;

    return 0;
}