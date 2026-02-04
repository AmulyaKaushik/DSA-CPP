#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2)
            return -1;

        int largest = nums[0];
        int slargest = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
            }
            else if (nums[i] < largest && nums[i] > slargest) {
                slargest = nums[i];
            }
        }

        if (slargest == INT_MIN)
            return -1;

        return slargest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 8, 6, 2};
    cout << sol.secondLargestElement(nums) << endl;
    return 0;
}
