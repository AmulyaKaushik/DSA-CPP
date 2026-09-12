#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Store the frequency of characters in ransomNote
        unordered_map<char, int> ran;

        // Store the frequency of characters in magazine
        unordered_map<char, int> mag;

        // Count characters in ransomNote
        for (auto c : ransomNote)
            ran[c]++;

        // Count characters in magazine
        for (auto c : magazine)
            mag[c]++;

        // Check whether magazine has enough
        // of every character required by ransomNote
        for (auto it : ran) {

            // If magazine has fewer occurrences,
            // ransomNote cannot be constructed
            if (it.second > mag[it.first])
                return false;
        }

        // All required characters are available
        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";

    Solution obj;

    bool result = obj.canConstruct(ransomNote, magazine);

    cout << "Can construct ransom note: "
         << (result ? "Yes" : "No") << endl;

    return 0;
}