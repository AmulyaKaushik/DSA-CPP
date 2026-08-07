#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Left boundary of the sliding window
        int low = 0;

        int n = fruits.size();

        // Store the maximum number of fruits collected
        int res = 0;

        // Store the frequency of each fruit type
        unordered_map<int, int> mpp;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current fruit in the window
            mpp[fruits[high]]++;

            // Shrink the window until it contains
            // at most two distinct fruit types
            while (mpp.size() > 2) {

                // Remove the leftmost fruit from the window
                mpp[fruits[low]]--;

                // Erase the fruit type if its frequency becomes zero
                if (mpp[fruits[low]] == 0)
                    mpp.erase(fruits[low]);

                low++;
            }

            // Update the maximum window size
            res = max(res, high - low + 1);
        }

        // Return the maximum number of fruits collected
        return res;
    }
};

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};

    Solution obj;

    int result = obj.totalFruit(fruits);

    cout << "Maximum fruits collected: " << result << endl;

    return 0;
}