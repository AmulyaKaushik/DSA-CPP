#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool fun(vector<int> &arr, int n, int guess, int k){

        // Place the first cow at the first stall
        int cow = 1;
        int prevPos = arr[0];

        for(int i = 1; i < n; i++){

            // Calculate the distance from the last placed cow
            int diff = arr[i] - prevPos;

            // Place the next cow if the minimum distance is satisfied
            if(diff >= guess){
                cow++;
                prevPos = arr[i];

                // Return true if all cows have been placed
                if(cow == k)
                    return true;
            }
        }

        // Not enough cows could be placed
        return false;
    }

    int aggressiveCows(vector<int> &arr, int k) {

        int n = arr.size();

        // Sort stalls by position
        sort(arr.begin(), arr.end());

        // Minimum possible distance
        int low = 1;

        int res = -1;

        // Maximum possible distance
        int high = arr[n - 1] - arr[0];

        while(low <= high){

            // Try the middle distance
            int guess = (low + high) / 2;

            // Check whether all cows can be placed
            if(fun(arr, n, guess, k)){
                res = guess;

                // Try to maximize the minimum distance
                low = guess + 1;
            }
            else{

                // Distance is too large, try a smaller one
                high = guess - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> arr = {1, 2, 4, 8, 9};
    int k = 3;

    Solution obj;

    int result = obj.aggressiveCows(arr, k);

    cout << "Maximum minimum distance: " << result << endl;

    return 0;
}