#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:

    // Checks whether the current window
    // contains all required characters
    bool sahi(unordered_map<char, int>& have,
              unordered_map<char, int>& needed) {

        for (auto it : needed) {

            // If any required character is missing
            // or its frequency is insufficient
            if (have[it.first] < it.second) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {

        // Edge cases
        if (s.size() < t.size() || s.empty() || t.empty())
            return "";

        int n = s.size();

        // Starting index of the minimum window
        int start = 0;

        // Length of the minimum window found
        int res = INT_MAX;

        // Stores character frequencies in the current window
        unordered_map<char, int> have;

        // Stores required character frequencies
        unordered_map<char, int> needed;

        // Build the frequency map for string t
        for (auto ch : t) {
            needed[ch]++;
        }

        // Left boundary of the sliding window
        int low = 0;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current character
            have[s[high]]++;

            // Shrink the window while it remains valid
            while (sahi(have, needed)) {

                int len = high - low + 1;

                // Update the minimum window
                if (res > len) {
                    res = len;
                    start = low;
                }

                // Remove the leftmost character
                // and shrink the window
                have[s[low]]--;
                low++;
            }
        }

        // If no valid window exists
        if (res == INT_MAX)
            return "";

        // Return the minimum window substring
        return s.substr(start, res);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution obj;

    string result = obj.minWindow(s, t);

    cout << "Minimum window substring: " << result << endl;

    return 0;
}