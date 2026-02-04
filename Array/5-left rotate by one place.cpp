#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        if (nums.size() == 0) return;

        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = temp;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5};
    sol.rotateArrayByOne(nums);

    cout << "Array after left rotation by 1: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
