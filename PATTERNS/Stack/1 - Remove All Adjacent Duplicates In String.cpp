#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size();

        // Use a stack to keep track of characters
        stack<char> st;

        // Traverse the string
        for (int i = 0; i < n; i++) {

            // If stack is empty or current character
            // is different from the top, push it
            if (st.empty() || s[i] != st.top()) {
                st.push(s[i]);
            }

            // If current character matches the top,
            // remove the duplicate character
            else {
                st.pop();
            }
        }

        // Build the answer from the stack
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse because stack gives characters in reverse order
        reverse(ans.begin(), ans.end());

        // Return the final string
        return ans;
    }
};

int main() {
    string s = "abbaca";

    Solution obj;

    string result = obj.removeDuplicates(s);

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}