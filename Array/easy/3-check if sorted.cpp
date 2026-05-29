#include <bits/stdc++.h>
using namespace std;

class Solution {	
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 4, 5};
    vector<int> nums2 = {1, 3, 2, 4};

    cout << sol.isSorted(nums1) << endl; // 1 (true)
    cout << sol.isSorted(nums2) << endl; // 0 (false)

    return 0;
}
