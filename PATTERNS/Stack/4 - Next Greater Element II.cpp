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

        // Traverse the array twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Use modulo to access elements circularly
            int curr = nums[i % n];

            // Remove elements smaller than or equal to
            // the current element
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // Only store results during the second traversal
            if (i < n) {

                // No greater element found
                if (st.empty()) {
                    res[i] = -1;
                }

                // Top element is the next greater element
                else {
                    res[i] = st.top();
                }
            }

            // Push the current element into the stack
            st.push(curr);
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