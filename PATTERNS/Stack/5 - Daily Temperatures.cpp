#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        // Stack stores indices of potential warmer days
        stack<int> st;

        // Store the number of days until a warmer temperature
        vector<int> res(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all days with temperature
            // less than or equal to the current temperature
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // No warmer day exists
            if (st.empty()) {
                res[i] = 0;
            }

            // Top of stack gives the nearest warmer day
            else {
                res[i] = st.top() - i;
            }

            // Push current day's index into the stack
            st.push(i);
        }

        // Return the result
        return res;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution obj;

    vector<int> result = obj.dailyTemperatures(temperatures);

    cout << "Days until warmer temperature: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}