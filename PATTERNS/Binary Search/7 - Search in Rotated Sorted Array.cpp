#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high){

            int mid = (low + high) / 2;

            // Target found
            if(nums[mid] == target){
                return mid;
            }

            else{

                // Part 1: mid lies in the left sorted portion
                if(nums[mid] > nums[n - 1]){

                    // Target is greater than mid,
                    // so move towards the right
                    if(nums[mid] < target){
                        low = mid + 1;
                    }

                    else{

                        // Target belongs to the rotated right portion
                        if(nums[0] > target){
                            low = mid + 1;
                        }

                        // Target belongs to the left portion
                        else{
                            high = mid - 1;
                        }
                    }
                }

                // Part 2: mid lies in the right sorted portion
                else{

                    // Target is smaller than mid,
                    // so move towards the left
                    if(nums[mid] > target){
                        high = mid - 1;
                    }

                    else{

                        // Target belongs to the left rotated portion
                        if(nums[n - 1] < target){
                            high = mid - 1;
                        }

                        // Target belongs to the right portion
                        else{
                            low = mid + 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;

    int result = obj.search(nums, target);

    cout << "Target index: " << result << endl;

    return 0;
}