#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {

        int n = start.size();

        // Sort all meeting start times
        sort(start.begin(), start.end());

        // Sort all meeting end times
        sort(end.begin(), end.end());

        // i -> points to the next meeting start time
        // j -> points to the next meeting end time
        // rooms -> current number of rooms in use
        // res -> maximum number of rooms needed
        int i = 0, j = 0, rooms = 0, res = 0;

        // Process all meeting start times
        while (i < n) {

            // If a meeting starts before the earliest
            // current meeting ends, we need another room
            if (start[i] < end[j]) {
                rooms++;

                // Update maximum rooms required
                res = max(res, rooms);

                i++;
            }

            // Otherwise, a room becomes free
            else {
                rooms--;
                j++;
            }
        }

        // Return the minimum number of rooms required
        return res;
    }
};

int main() {
    vector<int> start = {1, 10, 7};
    vector<int> end = {4, 15, 10};

    Solution obj;

    int result = obj.minMeetingRooms(start, end);

    cout << "Minimum meeting rooms required: " << result << endl;

    return 0;
}