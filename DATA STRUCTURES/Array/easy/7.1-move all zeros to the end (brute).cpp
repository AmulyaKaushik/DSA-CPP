#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        // Copy non-zero elements back
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        // Fill remaining positions with zeros
        for (int i = temp.size(); i < n; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
