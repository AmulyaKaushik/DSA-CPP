#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        // Initialize three pointers:
        // low  -> boundary for 0s
        // mid  -> current element being processed
        // high -> boundary for 2s
        int low = 0, mid = 0, high = n - 1;

        // Process elements until mid crosses high
        while (mid <= high) {

            // If current element is 0,
            // place it at the beginning
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }

            // If current element is 1,
            // it is already in the correct region
            else if (nums[mid] == 1) {
                mid++;
            }

            // If current element is 2,
            // place it at the end
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;

    obj.sortColors(nums);

    cout << "Sorted colors: ";

    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}