#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largest)
                largest = nums[i];
        }
        return largest;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 1, 8, 2};
    cout << sol.largestElement(nums) << endl;

    return 0;
}
