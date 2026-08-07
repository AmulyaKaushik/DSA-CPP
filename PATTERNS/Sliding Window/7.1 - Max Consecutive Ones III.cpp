#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    // Returns the frequency of 1s
    // in the current sliding window
    int find(unordered_map<int, int>& mpp) {

        int maxFreq = 0;

        for (auto it : mpp) {
            if (it.first == 1 && it.second > maxFreq)
                maxFreq = it.second;
        }

        return maxFreq;
    }

    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        // Left boundary of the sliding window
        int low = 0;

        // Store the maximum valid window length
        int res = INT_MIN;

        // Store the frequency of 0s and 1s
        // in the current window
        unordered_map<int, int> f;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current element
            f[nums[high]]++;

            // Current window length
            int len = high - low + 1;

            // Number of 1s in the current window
            int maxfreq = find(f);

            // Number of 0s that need to be flipped
            int diff = len - maxfreq;

            // Shrink the window until
            // at most k zeros need to be flipped
            while (diff > k) {
                f[nums[low]]--;
                low++;

                len = high - low + 1;
                maxfreq = find(f);
                diff = len - maxfreq;
            }

            // Update the maximum valid window length
            res = max(res, high - low + 1);
        }

        // Return the longest valid subarray length
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