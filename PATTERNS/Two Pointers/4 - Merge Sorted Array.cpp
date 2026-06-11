#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Create a temporary array to store the merged result
        vector<int> ans(m + n);

        // i -> traverses nums1
        // j -> traverses nums2
        // k -> traverses ans
        int i = 0, j = 0, k = 0;

        // Compare elements from both arrays and
        // place the smaller one into ans
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans[k] = nums1[i];
                k++;
                i++;
            }
            else {
                ans[k] = nums2[j];
                k++;
                j++;
            }
        }

        // Copy any remaining elements from nums1
        while (i < m) {
            ans[k] = nums1[i];
            k++;
            i++;
        }

        // Copy any remaining elements from nums2
        while (j < n) {
            ans[k] = nums2[j];
            k++;
            j++;
        }

        // Copy the merged result back into nums1
        for (int i = 0; i < ans.size(); i++) {
            nums1[i] = ans[i];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution obj;

    obj.merge(nums1, m, nums2, n);

    cout << "Merged array: ";

    for (int num : nums1) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}