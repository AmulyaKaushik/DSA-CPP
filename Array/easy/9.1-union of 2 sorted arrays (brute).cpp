#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        for(int i=0;i<nums1.size();i++)
            st.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            st.insert(nums2[i]);

        vector<int>temp;
        for(auto it:st)
            temp.push_back(it);

        return temp;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 6, 7};

    Solution obj;
    vector<int> result = obj.unionArray(nums1, nums2);

    for(int x : result)
        cout << x << " ";

    return 0;
}
