#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Store the maximum sum of a subarray
        // ending at the current index
        int bestending = nums[0];

        // Store the maximum subarray sum found so far
        int ans = nums[0];

        int n = nums.size();

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Either extend the previous subarray
            // or start a new subarray from the current element
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            // Choose the better option
            bestending = max(v1, v2);

            // Update the overall maximum
            ans = max(ans, bestending);
        }

        // Return the maximum subarray sum
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;

    int result = obj.maxSubArray(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}