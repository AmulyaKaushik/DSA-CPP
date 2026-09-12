#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        // Store the frequency of each character
        unordered_map<char, int> f;

        // Count each character in the string
        for (auto c : s)
            f[c]++;

        int length = 0;
        bool have_odd = false;

        // Use all even frequencies and the even part of odd frequencies
        for (auto it : f) {

            int count = it.second;

            if (count % 2 == 0) {

                // All occurrences can be used
                length += count;

            } else {

                // Use all but one occurrence
                length += (count - 1);

                // Keep one odd character for the center
                have_odd = true;
            }
        }

        // One odd-frequency character can be placed in the center
        if (have_odd)
            length++;

        return length;
    }
};

int main() {
    string s = "abccccdd";

    Solution obj;

    int result = obj.longestPalindrome(s);

    cout << "Longest palindrome length: " << result << endl;

    return 0;
}