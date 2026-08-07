#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // Left boundary of the sliding window
        int low = 0;

        int n = s.size();

        // Store the maximum length of a valid substring
        int res = 0;

        // Store the frequency of characters in the current window
        unordered_map<char, int> f;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current character in the window
            f[s[high]]++;

            // Shrink the window until it has at most k distinct characters
            while (f.size() > k) {

                // Remove the leftmost character from the window
                f[s[low]]--;

                // Erase the character if its frequency becomes zero
                if (f[s[low]] == 0)
                    f.erase(s[low]);

                low++;
            }

            // Update the maximum length if the window
            // contains exactly k distinct characters
            if (f.size() == k)
                res = max(res, high - low + 1);
        }

        // Return -1 if no valid substring exists
        return (res == 0) ? -1 : res;
    }
};

int main() {
    string s = "aabacbebebe";
    int k = 3;

    Solution obj;

    int result = obj.longestKSubstr(s, k);

    cout << "Length of longest substring with exactly "
         << k << " distinct characters: " << result << endl;

    return 0;
}