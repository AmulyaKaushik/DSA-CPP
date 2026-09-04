#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        // Stack stores opening brackets
        stack<char> st;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // Push opening brackets into the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);

            // Process closing brackets
            else {

                // If there is no opening bracket to match
                if (st.empty())
                    return false;

                // Match closing ')' with opening '('
                if (s[i] == ')' && st.top() == '(')
                    st.pop();

                // Match closing ']' with opening '['
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();

                // Match closing '}' with opening '{'
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();

                // Brackets do not match
                else
                    return false;
            }
        }

        // If stack is not empty, some opening brackets are unmatched
        if (!st.empty())
            return false;

        // All brackets are properly matched
        else
            return true;
    }
};

int main() {
    string s = "({[]})";

    Solution obj;

    bool result = obj.isValid(s);

    cout << "Valid parentheses: " << (result ? "Yes" : "No") << endl;

    return 0;
}