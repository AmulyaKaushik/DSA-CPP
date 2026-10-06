#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int first(vector<int>& a, int x){

        // Initialize the binary search range
        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // Search in the right half
            if(a[mid] < x){
                low = mid + 1;
            }

            // Search in the left half
            else if(a[mid] > x){
                high = mid - 1;
            }

            // Target found, continue searching to the left
            else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }

    int last(vector<int>& a, int x){

        // Initialize the binary search range
        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // Search in the right half
            if(a[mid] < x){
                low = mid + 1;
            }

            // Search in the left half
            else if(a[mid] > x){
                high = mid - 1;
            }

            // Target found, continue searching to the right
            else{
                res = mid;
                low = mid + 1;
            }
        }

        return res;
    }

    int countFreq(vector<int>& arr, int target) {

        // Find the first occurrence of the target
        int firstIndex = first(arr, target);

        // If target is not present, frequency is zero
        if(firstIndex == -1)
            return 0;

        // Find the last occurrence of the target
        int lastIndex = last(arr, target);

        // Number of occurrences is the distance between
        // first and last index, including both positions
        return lastIndex - firstIndex + 1;
    }
};

int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3, 4};
    int target = 2;

    Solution obj;

    int result = obj.countFreq(arr, target);

    cout << "Frequency of " << target << ": " << result << endl;

    return 0;
}