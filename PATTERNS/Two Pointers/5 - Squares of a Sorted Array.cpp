#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // Store negative and non-negative numbers separately
        vector<int> a;
        vector<int> b;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        // Square all elements in the negative array
        for (int i = 0; i < a.size(); i++) {
            a[i] = a[i] * a[i];
        }

        // Square all elements in the non-negative array
        for (int i = 0; i < b.size(); i++) {
            b[i] = b[i] * b[i];
        }

        // Reverse the negative array because after squaring,
        // its elements are in decreasing order
        reverse(a.begin(), a.end());

        // Merge the two sorted arrays
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        // Add remaining elements from a
        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        // Add remaining elements from b
        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        // Return the sorted squared array
        return ans;
    }
};

int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};

    Solution obj;

    vector<int> result = obj.sortedSquares(nums);

    cout << "Sorted Squares: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}