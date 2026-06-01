#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        long long total = 0;
        int res = 0;

        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];

            while ((long long)nums[r] * (r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 5;

    Solution obj;
    cout << obj.maxFrequency(nums, k) << endl;

    return 0;
}