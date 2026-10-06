#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {

        // Initialize the search range
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        // Store the index of the possible ceil
        int res = -1;

        while(low <= high){

            int mid = (low + high) / 2;

            // If arr[mid] can be the ceil,
            // store it and search for a smaller valid index
            if(arr[mid] >= x){
                res = mid;
                high = mid - 1;
            }

            // If arr[mid] is smaller than x,
            // search in the right half
            else{
                low = mid + 1;
            }
        }

        // Return the index of the smallest element >= x
        return res;
    }
};

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;

    Solution obj;

    int result = obj.findCeil(arr, x);

    cout << "Ceil index: " << result << endl;

    if(result != -1)
        cout << "Ceil value: " << arr[result] << endl;
    else
        cout << "Ceil does not exist" << endl;

    return 0;
}