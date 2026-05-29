#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;

        int j = -1;
        // find first zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // if no zero found, array is already fine
        if (j == -1) return;

        // move non-zero elements forward
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
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
