#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long num = x;
        long long rev = 0;
        bool flag = 0;

        if(num < 0){
            num = num * -1;
            flag = 1;
        }

        while(num > 0){
            int lastdigit = num % 10;
            rev = (rev * 10) + lastdigit;
            num = num / 10;
        }

        if(flag == 1){
            rev = rev * -1;
        }

        if(rev > INT_MAX || rev < INT_MIN)
            return 0;

        return (int)rev;
    }
};

int main() {
    Solution obj;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Reversed number: " << obj.reverse(x) << endl;

    return 0;
}