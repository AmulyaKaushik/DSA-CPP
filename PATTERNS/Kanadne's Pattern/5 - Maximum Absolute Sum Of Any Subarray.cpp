#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        // Maximum subarray sum ending at current index
        int maxending = nums[0];

        // Maximum subarray sum found so far
        int maxsum = nums[0];

        // Minimum subarray sum ending at current index
        int minending = nums[0];

        // Minimum subarray sum found so far
        int minsum = nums[0];

        // Store the maximum absolute sum found so far
        int res = abs(nums[0]);

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Find maximum subarray sum ending at current index
            maxending = max(maxending + nums[i], nums[i]);

            // Update the maximum subarray sum
            maxsum = max(maxsum, maxending);

            // Find minimum subarray sum ending at current index
            minending = min(minending + nums[i], nums[i]);

            // Update the minimum subarray sum
            minsum = min(minsum, minending);

            // Maximum absolute sum can come from
            // either the maximum positive sum or
            // the absolute value of the minimum negative sum
            res = max(maxsum, abs(minsum));
        }

        // Return the maximum absolute subarray sum
        return res;
    }
};

int main() {
    vector<int> nums = {1, -3, 2, 3, -4};

    Solution obj;

    int result = obj.maxAbsoluteSum(nums);

    cout << "Maximum absolute subarray sum: " << result << endl;

    return 0;
}