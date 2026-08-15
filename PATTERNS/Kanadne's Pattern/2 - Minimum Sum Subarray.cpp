#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubarraySum(vector<int>& arr) {

        // Store the minimum sum of a subarray
        // ending at the current index
        int bestending = arr[0];

        // Store the minimum subarray sum found so far
        int ans = arr[0];

        int n = arr.size();

        // Start from the second element
        for (int i = 1; i < n; i++) {

            // Either extend the previous subarray
            // or start a new subarray from the current element
            int v1 = bestending + arr[i];
            int v2 = arr[i];

            // Choose the smaller option
            bestending = min(v1, v2);

            // Update the overall minimum
            ans = min(ans, bestending);
        }

        // Return the minimum subarray sum
        return ans;
    }
};

int main() {
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};

    Solution obj;

    int result = obj.minSubarraySum(arr);

    cout << "Minimum subarray sum: " << result << endl;

    return 0;
}