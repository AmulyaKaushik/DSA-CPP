#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        // Initialize the binary search range
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // If nums[mid] is greater than the last element,
            // the minimum must be on the right side
            if(nums[mid] > nums[n - 1]){
                low = mid + 1;
            }

            // nums[mid] can be the minimum,
            // so store it and search further left
            else{
                res = mid;
                high = mid - 1;
            }
        }

        // Return the minimum element
        return nums[res];
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution obj;

    int result = obj.findMin(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}