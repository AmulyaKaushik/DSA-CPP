#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {

        int count = 0;

        // Remove the rightmost set bit in every iteration
        while(n > 0){

            // n & (n - 1) removes the lowest 1-bit
            n = n & (n - 1);

            // Count the removed set bit
            count++;
        }

        return count;
    }
};

int main() {
    int n = 11;

    Solution obj;

    int result = obj.hammingWeight(n);

    cout << "Number of 1 bits: " << result << endl;

    return 0;
}