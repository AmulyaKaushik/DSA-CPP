#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

        // Take the first interval as the current interval
        int n = intervals.size();
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        // Store the merged intervals
        vector<vector<int>> res;

        // Check all remaining intervals
        for (int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // If the intervals overlap, merge them
            if (end1 >= start2) {
                end1 = max(end1, end2);
            }

            // If there is no overlap, store the current interval
            // and start processing the new interval
            else {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        // Add the last interval
        res.push_back({start1, end1});

        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int n = intervals.size();

        // Track whether the new interval has been inserted
        bool insert = false;

        // Store all intervals along with the new interval
        vector<vector<int>> res;

        // Traverse all existing intervals
        for (int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Insert the new interval before the current interval
            // if its starting point comes first
            if (insert == false && newInterval[0] < start) {
                res.push_back({newInterval[0], newInterval[1]});
                insert = true;
            }

            // Add the current interval
            res.push_back({start, end});
        }

        // If the new interval has not been inserted yet,
        // add it at the end
        if (insert == false) {
            res.push_back({newInterval[0], newInterval[1]});
        }

        // Merge overlapping intervals
        res = mergeIntervals(res);

        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};

    Solution obj;

    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Intervals after insertion: ";

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}