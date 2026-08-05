#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int n = arr.size();

        // Initialize the sliding window
        int low = 0;
        int high = k - 1;

        // Calculate the sum of the first window
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum += arr[i];
        }

        // Store the maximum window sum found so far
        int res = 0;

        // Slide the window until the end of the array
        while (high < n) {

            // Update the maximum sum
            res = max(res, sum);

            // Move the window one step forward
            low++;
            high++;

            // Stop if the window has crossed the array
            if (high == n)
                break;

            // Remove the outgoing element and
            // add the incoming element
            sum = sum - arr[low - 1] + arr[high];
        }

        // Return the maximum subarray sum of size k
        return res;
    }
};

int main() {
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    Solution obj;

    int result = obj.maxSubarraySum(arr, k);

    cout << "Maximum subarray sum of size " << k << " = " << result << endl;

    return 0;
}