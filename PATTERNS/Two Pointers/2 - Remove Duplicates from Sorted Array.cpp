#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Edge case: empty array
        if (nums.empty())
            return 0;

        // i points to the last unique element found
        int i = 0;

        // Count of unique elements
        int res = 1;

        // j is used to traverse the array
        int j = 1;

        while (j < nums.size()) {

            // If current element is same as previous,
            // it is a duplicate, so skip it
            if (nums[j] == nums[j - 1]) {
                j++;
                continue;
            }

            // A new unique element is found

            // Place it right after the last unique element
            nums[i + 1] = nums[j];

            // Move i to the new last unique element
            i++;

            // Increase count of unique elements
            res++;

            // Move to the next element
            j++;
        }

        // Return the number of unique elements
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}