#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Left boundary of the sliding window
        int low = 0;

        // Store the maximum length of a valid substring
        int res = 0;

        int n = s.size();

        // Store the frequency of characters in the current window
        unordered_map<char, int> f;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current character in the window
            f[s[high]]++;

            // Shrink the window until all characters are unique
            while (f[s[high]] > 1) {

                // Remove the leftmost character from the window
                f[s[low]]--;
                low++;
            }

            // Update the maximum length of the valid window
            res = max(res, high - low + 1);
        }

        // Return the length of the longest substring
        return res;
    }
};

int main() {
    string s = "abcabcbb";

    Solution obj;

    int result = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}