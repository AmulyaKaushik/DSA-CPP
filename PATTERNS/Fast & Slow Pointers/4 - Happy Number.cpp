#include <iostream>
using namespace std;

class Solution {
public:
    int fun(int n) {

        // Calculate the sum of squares of digits
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum += (d * d);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        // Initialize slow and fast pointers
        int slow = n;
        int fast = n;

        // Continue until fast reaches 1
        while (fast != 1) {

            // Slow moves one step
            slow = fun(slow);

            // Fast moves two steps
            fast = fun(fun(fast));

            // If both pointers meet before reaching 1,
            // a cycle exists and the number is not happy
            if (slow == fast && slow != 1) {
                return false;
            }
        }

        // Number is happy if fast reaches 1
        return true;
    }
};

int main() {
    int n = 19;

    Solution obj;

    bool result = obj.isHappy(n);

    cout << "Is " << n << " a happy number? "
         << (result ? "Yes" : "No") << endl;

    return 0;
}