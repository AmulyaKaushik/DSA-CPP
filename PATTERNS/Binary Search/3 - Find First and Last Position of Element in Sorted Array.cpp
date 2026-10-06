#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int first(vector<int> &a, int x){

        // Initialize the search range
        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // Target is greater, so search in the right half
            if(a[mid] < x){
                low = mid + 1;
            }

            // Target is smaller, so search in the left half
            else if(a[mid] > x){
                high = mid - 1;
            }

            // Target found, store the index and continue left
            else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }

    int last(vector<int> &a, int x){

        // Initialize the search range
        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // Target is greater, so search in the right half
            if(a[mid] < x){
                low = mid + 1;
            }

            // Target is smaller, so search in the left half
            else if(a[mid] > x){
                high = mid - 1;
            }

            // Target found, store the index and continue right
            else{
                res = mid;
                low = mid + 1;
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        // Find the first and last occurrence of the target
        return {first(nums, target), last(nums, target)};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution obj;

    vector<int> result = obj.searchRange(nums, target);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

    return 0;
}