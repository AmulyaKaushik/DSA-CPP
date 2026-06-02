#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int count = 0, preSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            int remove = preSum - k;

            count += mpp[remove];

            mpp[preSum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Number of subarrays with sum " << k << " = "
         << sol.subarraySum(nums, k) << endl;

    return 0;
}