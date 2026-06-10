#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Initialize two pointers:
        // one at the beginning and one at the end
        int n = numbers.size();
        int i = 0, j = n - 1;

        while (i < j) {

            // Calculate the sum of the two elements
            int sum = numbers[i] + numbers[j];

            // If target is found, return 1-based indices
            if (sum == target)
                return {i + 1, j + 1};

            // If sum is smaller than target,
            // move left pointer to increase the sum
            else if (sum < target)
                i++;

            // If sum is greater than target,
            // move right pointer to decrease the sum
            else
                j--;
        }

        // Return {-1, -1} if no valid pair exists
        return {-1, -1};
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> result = obj.twoSum(numbers, target);

    cout << "Indices: ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}