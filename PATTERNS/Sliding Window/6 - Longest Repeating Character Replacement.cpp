#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    // Returns the maximum frequency of any character
    // present in the current sliding window
    int find(unordered_map<char, int>& mpp) {

        int maxFreq = 0;

        for (auto it : mpp) {
            if (it.second > maxFreq)
                maxFreq = it.second;
        }

        return maxFreq;
    }

    int characterReplacement(string s, int k) {

        // Left boundary of the sliding window
        int low = 0;

        // Store the maximum valid window length
        int res = INT_MIN;

        int n = s.size();

        // Store the frequency of characters
        // in the current window
        unordered_map<char, int> f;

        // Expand the window by moving the right boundary
        for (int high = 0; high < n; high++) {

            // Include the current character
            f[s[high]]++;

            // Current window length
            int len = high - low + 1;

            // Maximum frequency of any character
            // in the current window
            int maxfreq = find(f);

            // Characters that need replacement
            int diff = len - maxfreq;

            // Shrink the window until
            // replacements required are at most k
            while (diff > k) {
                f[s[low]]--;
                low++;

                len = high - low + 1;
                maxfreq = find(f);
                diff = len - maxfreq;
            }

            // Update the maximum valid window length
            res = max(res, high - low + 1);
        }

        // Return the longest valid substring length
        return res;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;

    Solution obj;

    int result = obj.characterReplacement(s, k);

    cout << "Longest substring length: " << result << endl;

    return 0;
}