#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                              vector<vector<int>>& secondList) {

        // Store all intersecting intervals
        vector<vector<int>> res;

        // Two pointers for both interval lists
        int i = 0, j = 0;

        int n1 = firstList.size();
        int n2 = secondList.size();

        // Process both lists until one is completely traversed
        while (i < n1 && j < n2) {

            // Start of intersection is the later starting point
            int start = max(firstList[i][0], secondList[j][0]);

            // End of intersection is the earlier ending point
            int end = min(firstList[i][1], secondList[j][1]);

            // If start <= end, the intervals overlap
            if (end >= start) {
                res.push_back({start, end});
            }

            // Move the pointer of the interval
            // that finishes first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }

        // Return all intersections
        return res;
    }
};

int main() {
    vector<vector<int>> firstList = {
        {0, 2},
        {5, 10},
        {13, 23},
        {24, 25}
    };

    vector<vector<int>> secondList = {
        {1, 5},
        {8, 12},
        {15, 24},
        {25, 26}
    };

    Solution obj;

    vector<vector<int>> result = obj.intervalIntersection(firstList, secondList);

    cout << "Interval intersections: ";

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}