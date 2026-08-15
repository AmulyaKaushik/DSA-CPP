#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Store the maximum product of a subarray
        // ending at the current index
        int maxending = nums[0];

        // Store the minimum product because a negative
        // number can turn it into the maximum product
        int minending = nums[0];

        // Store the maximum product found so far
        int ans = nums[0];

        int n = nums.size();

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Start a new subarray from the current element
            int v1 = nums[i];

            // Extend the previous maximum product
            int v2 = maxending * nums[i];

            // Extend the previous minimum product
            // which can become maximum if nums[i] is negative
            int v3 = minending * nums[i];

            // Find the maximum product ending at current index
            maxending = max(v1, max(v2, v3));

            // Find the minimum product ending at current index
            minending = min(v1, min(v2, v3));

            // Update the overall maximum product
            ans = max(ans, maxending);
        }

        // Return the maximum product
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};

    Solution obj;

    int result = obj.maxProduct(nums);

    cout << "Maximum product: " << result << endl;

    return 0;
}