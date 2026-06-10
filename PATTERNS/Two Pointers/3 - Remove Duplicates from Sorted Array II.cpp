#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // If the array has 2 or fewer elements,
        // all elements can remain as they are
        if (nums.size() <= 2)
            return nums.size();

        // i points to the index of the second occurrence
        // allowed in the modified array
        int i = 1;

        // At least first two elements are included
        int res = 2;

        // j traverses the array starting from index 2
        int j = 2;

        while (j < nums.size()) {

            // If current element matches the element
            // two positions before the insertion point,
            // it would create more than two duplicates
            if (nums[j] == nums[i - 1]) {
                j++;
                continue;
            }

            // Place the valid element in the next position
            nums[i + 1] = nums[j];

            // Move insertion pointer forward
            i++;

            // Increase count of valid elements
            res++;

            // Move to the next element
            j++;
        }

        // Return the length of the modified array
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Number of elements after removal: " << k << endl;

    cout << "Modified array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}