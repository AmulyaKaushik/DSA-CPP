#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // Initialize the binary search range
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // If the next element is greater,
            // we are on the increasing side of the mountain
            if(arr[mid] < arr[mid + 1]){
                low = mid + 1;
            }

            // We are on the decreasing side,
            // so mid can be the peak
            else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> arr = {0, 2, 5, 7, 6, 4, 2};

    Solution obj;

    int result = obj.peakIndexInMountainArray(arr);

    cout << "Peak index: " << result << endl;
    cout << "Peak value: " << arr[result] << endl;

    return 0;
}