#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long fun(vector<int>& piles, int n, int speed) {

        // Calculate the total hours needed at the given speed
        long long hour = 0;

        for(int i = 0; i < n; i++){

            // Calculate ceil(piles[i] / speed)
            // This is the number of hours needed for this pile
            hour += (piles[i] / speed) + ((piles[i] % speed) != 0);
        }

        return hour;
    }

    int maxOfArr(vector<int> piles, int n) {

        // Find the largest pile
        int maxx = piles[0];

        for(int i = 1; i < n; i++){

            if(piles[i] > maxx){
                maxx = piles[i];
            }
        }

        return maxx;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        // Minimum possible eating speed
        int low = 1;

        // Maximum possible eating speed
        int high = maxOfArr(piles, n);

        int res = -1;

        while(low <= high){

            // Try the middle speed
            int guess = (low + high) / 2;

            // Calculate total hours needed at this speed
            long long hour = fun(piles, n, guess);

            // Too slow, so increase the speed
            if(hour > h){
                low = guess + 1;
            }

            // Speed is sufficient, try to find a smaller speed
            else{
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;

    int result = obj.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}