#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        // Calculate the total sum of the array
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Check if index 0 is the pivot
        if (sum - nums[0] == 0) {
            return 0;
        }

        // Store the sum of elements to the left
        int left = 0;

        int right;

        // Check each index as a possible pivot
        for (int i = 1; i < n; i++) {

            // Add the previous element to the left sum
            left += nums[i - 1];

            // Calculate the sum of elements to the right
            right = sum - left - nums[i];

            // If both sides have equal sums, return the index
            if (left == right)
                return i;
        }

        // No pivot index found
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution obj;

    int result = obj.pivotIndex(nums);

    cout << "Pivot index: " << result << endl;

    return 0;
}