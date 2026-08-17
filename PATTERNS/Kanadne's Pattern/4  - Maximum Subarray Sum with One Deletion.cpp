#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        // Maximum sum ending at current index
        // without deleting any element
        int nodelete = arr[0];

        // Maximum sum ending at current index
        // after deleting exactly one element
        int onedelete = INT_MIN;

        // Store the maximum sum found so far
        int res = arr[0];

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Store previous values before updating them
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;

            // Case 1: Don't delete the current element
            // Either extend the previous subarray or start a new one
            nodelete = max(prevnodelete + arr[i], arr[i]);

            int v2;

            // If no element has been deleted yet,
            // delete the current element
            if (prevonedelete == INT_MIN)
                v2 = arr[i];

            // Otherwise, keep the previous deletion
            // and include the current element
            else
                v2 = prevonedelete + arr[i];

            // Case 2: Delete one element
            // Either delete the current element
            // or use the previous subarray with one deletion
            onedelete = max(v2, prevnodelete);

            // Update the overall maximum
            res = max(res, max(onedelete, nodelete));
        }

        // Return the maximum subarray sum
        // with at most one deletion
        return res;
    }
};

int main() {
    vector<int> arr = {1, -2, 0, 3};

    Solution obj;

    int result = obj.maximumSum(arr);

    cout << "Maximum subarray sum with one deletion: "
         << result << endl;

    return 0;
}