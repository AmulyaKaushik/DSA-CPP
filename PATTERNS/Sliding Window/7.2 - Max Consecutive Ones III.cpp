#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        // Left boundary of the sliding window
        int low = 0;

        // Store the maximum valid window length
        int res = INT_MIN;

        // Count the number of zeros
        // in the current window
        int zerocount = 0;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Count the current zero
            if (nums[high] == 0)
                zerocount++;

            // Shrink the window until
            // at most k zeros remain
            while (zerocount > k) {

                // Remove the leftmost zero if present
                if (nums[low] == 0)
                    zerocount--;

                low++;
            }

            // Update the maximum valid window length
            res = max(res, high - low + 1);
        }

        // Return the longest subarray length
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    Solution obj;

    int result = obj.longestOnes(nums, k);

    cout << "Longest subarray length: " << result << endl;

    return 0;
}