#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // Left boundary of the sliding window
        int low = 0;

        // Store the minimum valid window length
        int min_len = INT_MAX;

        // Store the sum of the current window
        int current_sum = 0;

        int n = nums.size();

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Add the current element to the window
            current_sum += nums[high];

            // Shrink the window while its sum is at least the target
            while (current_sum >= target) {

                // Update the minimum window length
                min_len = min(min_len, high - low + 1);

                // Remove the leftmost element and shrink the window
                current_sum -= nums[low];
                low++;
            }
        }

        // If no valid subarray exists, return 0
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    Solution obj;

    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum subarray length: " << result << endl;

    return 0;
}