#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countTriplets(int sum, vector<int>& arr) {

        int n = arr.size();

        // Store the count of valid triplets
        int counter = 0;

        // Sort the array for the two-pointer approach
        sort(arr.begin(), arr.end());

        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; i++) {

            // Initialize two pointers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                // Calculate the current triplet sum
                int s = arr[i] + arr[left] + arr[right];

                // If the sum is less than the target,
                // then all elements between left and right
                // will also form valid triplets
                if (s < sum) {
                    counter = counter + (right - left);
                    left++;
                }

                // Otherwise, decrease the sum
                // by moving the right pointer
                else {
                    right--;
                }
            }
        }

        // Return the total count of valid triplets
        return counter;
    }
};

int main() {
    vector<int> arr = {-2, 0, 1, 3};
    int sum = 2;

    Solution obj;

    int result = obj.countTriplets(sum, arr);

    cout << "Number of triplets: " << result << endl;

    return 0;
}