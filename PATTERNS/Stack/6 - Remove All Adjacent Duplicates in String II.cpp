#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {

        int n = s.size();

        // Stack stores character and its consecutive frequency
        stack<pair<char, int>> st;

        // Traverse the string
        for (int i = 0; i < n; i++) {

            // If stack is empty or current character
            // is different from the top character
            if (st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            }

            else {

                // If frequency is less than k - 1,
                // increase the frequency
                if (st.top().second < (k - 1)) {

                    pair<char, int> p = st.top();
                    st.pop();

                    st.push({p.first, p.second + 1});
                }

                // If frequency reaches k, remove the group
                else {
                    st.pop();
                }
            }
        }

        // Build the result string from the stack
        string res = "";

        while (!st.empty()) {

            pair<char, int> p = st.top();
            st.pop();

            // Add the character according to its frequency
            while (p.second--) {
                res += p.first;
            }
        }

        // Stack gives the characters in reverse order
        reverse(res.begin(), res.end());

        // Return the final string
        return res;
    }
};

int main() {
    string s = "deeedbbcccbdaa";
    int k = 3;

    Solution obj;

    string result = obj.removeDuplicates(s, k);

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}