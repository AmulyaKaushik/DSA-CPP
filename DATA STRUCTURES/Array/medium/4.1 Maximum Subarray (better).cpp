#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        for(int l=0;l<n;l++){
            int currentsum = 0;
            for(int r=l;r<n;r++){
                currentsum += nums[r];
                maxsum = max(maxsum, currentsum);
            }
        }
        return maxsum;
    }
};

int main() {
    // Instantiate the Solution object
    Solution solver;

    // Test Case 1: Standard mixed array
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 Expected: 6 | Got: " << solver.maxSubArray(nums1) << endl;

    // Test Case 2: Single element array
    vector<int> nums2 = {1};
    cout << "Test 2 Expected: 1 | Got: " << solver.maxSubArray(nums2) << endl;

    // Test Case 3: All negative numbers
    vector<int> nums3 = {-5, -1, -3, -2};
    cout << "Test 3 Expected: -1 | Got: " << solver.maxSubArray(nums3) << endl;

    return 0;
}
