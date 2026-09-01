#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        // Store the count of zeros
        int zero = 0;

        // Store the count of ones
        int one = 0;

        // Store the first index where each difference occurs
        unordered_map<int, int> f;

        // Store the maximum length found
        int res = 0;

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // Update zero and one counts
            if (nums[i] == 0) {
                zero++;
            }
            else {
                one++;
            }

            // Difference between number of zeros and ones
            int diff = zero - one;

            // If difference is zero, the entire prefix
            // contains equal number of zeros and ones
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            }

            // Store the first occurrence of this difference
            if (f.find(diff) == f.end()) {
                f[diff] = i;
            }
            else {

                // If the same difference occurs again,
                // the elements between the two indices
                // contain equal zeros and ones
                int idx = f[diff];
                int len = i - idx;

                res = max(res, len);
            }
        }

        // Return the maximum length
        return res;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 1, 0};

    Solution obj;

    int result = obj.findMaxLength(nums);

    cout << "Maximum length of subarray with equal 0s and 1s: "
         << result << endl;

    return 0;
}