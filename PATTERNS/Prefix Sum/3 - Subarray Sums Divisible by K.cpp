#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        // Store the number of subarrays whose sum
        // is divisible by k
        int count = 0;

        // Store the current prefix sum
        int sum = 0;

        // Store the frequency of each remainder
        unordered_map<int, int> f;

        // Remainder 0 occurs once initially
        f[0] = 1;

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // Update the prefix sum
            sum += nums[i];

            // Calculate the remainder
            int rem = sum % k;

            // Convert negative remainder to positive
            if (rem < 0)
                rem += k;

            // If the same remainder appeared before,
            // the subarray between those positions is divisible by k
            count += f[rem];

            // Store the current remainder
            f[rem]++;
        }

        // Return the total count
        return count;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution obj;

    int result = obj.subarraysDivByK(nums, k);

    cout << "Number of subarrays divisible by " << k << ": "
         << result << endl;

    return 0;
}