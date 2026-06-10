#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int maxFreq = 0;
        int maxElement = nums[0];

        for(auto it : mpp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                maxElement = it.first;
            }
        }

        return maxElement;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Majority Element: " << obj.majorityElement(nums) << endl;

    return 0;
}