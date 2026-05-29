#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int more = target - a;

            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }

            mpp[a] = i;
        }

        return {-1, -1};
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: " << ans[0] << " " << ans[1] << endl;

    return 0;
}