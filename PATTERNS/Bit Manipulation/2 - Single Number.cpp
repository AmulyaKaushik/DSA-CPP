#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        int x = 0;

        // XOR all elements
        // Equal numbers cancel each other because a ^ a = 0
        for(int i = 0; i < n; i++){
            x = x ^ nums[i];
        }

        // The remaining value is the number that appears only once
        return x;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution obj;

    int result = obj.singleNumber(nums);

    cout << "Single number: " << result << endl;

    return 0;
}