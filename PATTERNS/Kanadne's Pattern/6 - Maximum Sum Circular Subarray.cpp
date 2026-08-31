#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        // Maximum subarray sum ending at current index
        int maxending = nums[0];

        // Maximum subarray sum found so far
        int maxsum = nums[0];

        // Minimum subarray sum ending at current index
        int minending = nums[0];

        // Minimum subarray sum found so far
        int minsum = nums[0];

        // Store the total sum of the array
        int arrsum = nums[0];

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Calculate total array sum
            arrsum += nums[i];

            // Find maximum subarray sum ending at current index
            maxending = max(nums[i], maxending + nums[i]);

            // Update maximum subarray sum
            maxsum = max(maxsum, maxending);

            // Find minimum subarray sum ending at current index
            minending = min(nums[i], minending + nums[i]);

            // Update minimum subarray sum
            minsum = min(minsum, minending);
        }

        // If all elements are negative, the circular
        // calculation would incorrectly give 0
        if (maxsum < 0)
            return maxsum;

        // Circular maximum = total sum - minimum subarray sum
        return max(maxsum, arrsum - minsum);
    }
};

int main() {
    vector<int> nums = {1, -2, 3, -2};

    Solution obj;

    int result = obj.maxSubarraySumCircular(nums);

    cout << "Maximum circular subarray sum: " << result << endl;

    return 0;
}