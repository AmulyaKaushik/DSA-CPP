#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int currentsum = 0;

            for(int j = i; j < n; j++) {
                currentsum += nums[j];

                if(currentsum == k)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    Solution obj;
    cout << obj.subarraySum(nums, k);

    return 0;
}