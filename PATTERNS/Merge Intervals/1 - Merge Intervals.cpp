#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals based on their starting points
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        // Store the merged intervals
        vector<vector<int>> res;

        // Take the first interval as the current interval
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        // Check remaining intervals
        for (int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // If intervals overlap, merge them
            if (end1 >= start2) {
                end1 = max(end1, end2);
            }

            // If there is no overlap, store the current interval
            // and start a new interval
            else {
                res.push_back({start1, end1});

                start1 = start2;
                end1 = end2;
            }
        }

        // Add the last interval
        res.push_back({start1, end1});

        // Return the merged intervals
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    Solution obj;

    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged intervals: ";

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}