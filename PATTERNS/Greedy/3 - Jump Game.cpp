#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        // Store the farthest index we can currently reach
        int n = nums.size();
        int reach = 0;

        for(int i = 0; i < n; i++){

            // If the current index is beyond our reachable range,
            // then we cannot reach this position
            if(reach < i)
                return false;

            // Update the farthest position we can reach
            reach = max(i + nums[i], reach);

            // If we can already reach the last index,
            // return true immediately
            if(reach >= n - 1)
                return true;
        }

        return true;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution obj;

    bool result = obj.canJump(nums);

    cout << (result ? "Can reach the last index" : "Cannot reach the last index") << endl;

    return 0;
}