#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        for(int i = 0; i < count0; i++) {
            nums[i] = 0;
        }

        for(int i = count0; i < count0 + count1; i++) {
            nums[i] = 1;
        }

        for(int i = count0 + count1; i < n; i++) {
            nums[i] = 2;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (0, 1, 2 only): ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted array: ";
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}