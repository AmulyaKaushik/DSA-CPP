#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        // Stack stores elements for which we are finding the next greater element
        stack<int> st;

        // Store the next greater element for each number in nums2
        unordered_map<int, int> mp;

        // Traverse nums2 from right to left
        for (int i = m - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to
            // the current element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If no greater element exists
            if (st.empty()) {
                mp[nums2[i]] = -1;
            }

            // Top element is the next greater element
            else {
                mp[nums2[i]] = st.top();
            }

            // Push current element into the stack
            st.push(nums2[i]);
        }

        // Store answers for nums1
        vector<int> ans;

        // Get the next greater element for each element of nums1
        for (int i = 0; i < n; i++) {
            ans.push_back(mp[nums1[i]]);
        }

        // Return the result
        return ans;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution obj;

    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}