#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.size();

        // Store the frequency of each character
        unordered_map<char, int> mpp;

        // Count the occurrences of every character
        for (auto c : s) {
            mpp[c]++;
        }

        // Find the first character that occurs only once
        for (int i = 0; i < n; i++) {

            // If frequency is 1, return its index
            if (mpp[s[i]] == 1)
                return i;
        }

        // Return -1 if no unique character exists
        return -1;
    }
};

int main() {
    string s = "leetcode";

    Solution obj;

    int result = obj.firstUniqChar(s);

    cout << "Index of first unique character: " << result << endl;

    return 0;
}