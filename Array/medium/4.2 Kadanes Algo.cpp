#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = nums[0];
        int maxsum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currentsum = max(nums[i], currentsum + nums[i]);
            maxsum = max(maxsum, currentsum);
        }

        return maxsum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;
    cout << "Maximum Subarray Sum: " << obj.maxSubArray(nums) << endl;

    return 0;
}