#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Stack stores potential next greater elements
        stack<int> st;

        // Store the answer for each element
        vector<int> res(n);

        // Push elements except the last one
        // to simulate the circular nature of the array
        for (int i = n - 2; i >= 0; i--) {
            st.push(nums[i]);
        }

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to
            // the current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // No greater element exists
            if (st.empty()) {
                res[i] = -1;
            }

            // Top element is the next greater element
            else {
                res[i] = st.top();
            }

            // Push the current element for future elements
            st.push(nums[i]);
        }

        // Return the result
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};

    Solution obj;

    vector<int> result = obj.nextGreaterElements(nums);

    cout << "Next greater elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}