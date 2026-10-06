#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Initialize the search range
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        // Continue while the search range is valid
        while(low <= high){

            // Find the middle index
            int mid = (low + high) / 2;

            // Target found at mid
            if(nums[mid] == target){
                return mid;
            }

            // Target is greater, so search in the right half
            else if(nums[mid] < target){
                low = mid + 1;
            }

            // Target is smaller, so search in the left half
            else{
                high = mid - 1;
            }
        }

        // Target does not exist in the array
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    Solution obj;

    int result = obj.search(nums, target);

    cout << "Target index: " << result << endl;

    return 0;
}