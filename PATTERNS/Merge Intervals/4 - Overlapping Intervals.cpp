#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isIntersect(vector<vector<int>> intervals) {

        // Sort intervals based on their starting points
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        // Store the ending point of the first interval
        int end1 = intervals[0][1];

        // Check the remaining intervals
        for (int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // If the current interval starts
            // before the previous one ends, they intersect
            if (end1 >= start2) {
                return true;
            }

            // Update the ending point
            // for the next comparison
            else {
                end1 = end2;
            }
        }

        // No overlapping intervals found
        return false;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {5, 7},
        {2, 4}
    };

    Solution obj;

    bool result = obj.isIntersect(intervals);

    cout << "Intervals intersect: " << (result ? "Yes" : "No") << endl;

    return 0;
}