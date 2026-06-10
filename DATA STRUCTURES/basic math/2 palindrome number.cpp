#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long num = x;

        if (num < 0) return false;

        long long rev = 0;

        while (num > 0) {
            int last = num % 10;
            rev = (rev * 10) + last;
            num = num / 10;
        }

        return x == rev;
    }
};

int main() {
    Solution obj;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (obj.isPalindrome(x))
        cout << x << " is a palindrome." << endl;
    else
        cout << x << " is not a palindrome." << endl;

    return 0;
}