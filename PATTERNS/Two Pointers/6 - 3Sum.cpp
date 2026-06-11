#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Store all valid triplets
        vector<vector<int>> res;

        int n = nums.size();

        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());

        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers for finding the remaining two elements
            int left = i + 1;
            int right = n - 1;

            // Target sum needed from left and right elements
            int sum = (-1) * nums[i];

            while (left < right) {

                // Current sum of the two-pointer elements
                int s = nums[left] + nums[right];

                // Valid triplet found
                if (s == sum) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values for left pointer
                    while (left < n && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate values for right pointer
                    while (right >= 0 && nums[right] == nums[right + 1])
                        right--;
                }

                // Need a larger sum
                else if (s < sum)
                    left++;

                // Need a smaller sum
                else
                    right--;
            }
        }

        // Return all unique triplets
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution obj;

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets:" << endl;

    for (auto triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}