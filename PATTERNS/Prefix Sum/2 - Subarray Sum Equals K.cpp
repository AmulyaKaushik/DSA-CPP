#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Store the frequency of each prefix sum
        unordered_map<int, int> f;

        // Prefix sum of 0 occurs once initially
        f[0] = 1;

        // Store the current prefix sum
        int prefixsum = 0;

        // Store the number of subarrays with sum k
        int count = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Update the prefix sum
            prefixsum += nums[i];

            // Find the prefix sum needed to form a subarray of sum k
            int ques = prefixsum - k;

            // Add the number of times this required prefix sum
            // has already occurred
            count += f[ques];

            // Store the current prefix sum
            f[prefixsum]++;
        }

        // Return the total number of valid subarrays
        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution obj;

    int result = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << ": "
         << result << endl;

    return 0;
}