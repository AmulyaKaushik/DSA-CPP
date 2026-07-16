#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Store the minimum difference encountered
        int max_diff = INT_MAX;

        // Store the sum closest to the target
        int res_sum;

        // Sort the array for the two-pointer approach
        sort(nums.begin(), nums.end());

        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; i++) {

            // Initialize two pointers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                // Calculate the current triplet sum
                int sum = nums[i] + nums[left] + nums[right];

                // If exact target is found, return immediately
                if (sum == target) {
                    return sum;
                }

                // Calculate the difference from the target
                int diff = abs(sum - target);

                // Update the closest sum if a smaller difference is found
                if (max_diff > diff) {
                    max_diff = diff;
                    res_sum = sum;
                }

                // Increase the sum by moving the left pointer
                else if (sum < target) {
                    left++;
                }

                // Decrease the sum by moving the right pointer
                else {
                    right--;
                }
            }
        }

        // Return the closest sum found
        return res_sum;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    Solution obj;

    int result = obj.threeSumClosest(nums, target);

    cout << "Closest Sum: " << result << endl;

    return 0;
}