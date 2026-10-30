#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Find the number of rows and columns
        int row = matrix.size();
        int column = matrix[0].size();

        int r = -1;
        int low = 0;
        int high = row - 1;

        // First binary search: Find the correct row
        while(low <= high){

            int guess = (low + high) / 2;

            // If the first element of this row is <= target,
            // this row can be a possible candidate
            if(matrix[guess][0] <= target){
                r = guess;
                low = guess + 1;
            }
            else{
                high = guess - 1;
            }
        }

        // No row can contain the target
        if(r == -1)
            return false;

        // Second binary search: Search inside the selected row
        low = 0;
        high = column - 1;

        while(low <= high){

            int guess = (low + high) / 2;

            // Target found
            if(matrix[r][guess] == target)
                return true;

            // Search in the right half
            else if(matrix[r][guess] < target)
                low = guess + 1;

            // Search in the left half
            else
                high = guess - 1;
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    Solution obj;

    bool result = obj.searchMatrix(matrix, target);

    cout << (result ? "Target found" : "Target not found") << endl;

    return 0;
}