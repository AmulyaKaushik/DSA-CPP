#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        string b = "balloon";

        // Store the required frequency of each character
        unordered_map<char, int> need;

        // Store the available frequency of each character
        unordered_map<char, int> have;

        // Count characters required to form "balloon"
        for (auto c : b)
            need[c]++;

        // Count characters available in text
        for (auto c : text)
            have[c]++;

        // Start with the maximum possible answer
        int res = INT_MAX;

        // Find how many complete "balloon" strings
        // can be formed for each required character
        for (auto it : need) {

            // Divide available frequency by required frequency
            // and take the minimum among all characters
            res = min(res, have[it.first] / it.second);
        }

        // Return the maximum number of "balloon" strings
        return res;
    }
};

int main() {
    string text = "nlaebolko";

    Solution obj;

    int result = obj.maxNumberOfBalloons(text);

    cout << "Maximum number of balloons: " << result << endl;

    return 0;
}