#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Find the number of rows and columns
        int nrow = matrix.size();
        int ncol = matrix[0].size();

        // Start from the bottom-left corner
        int r = nrow - 1;
        int c = 0;

        while(r >= 0 && c < ncol){

            // Target found
            if(matrix[r][c] == target)
                return true;

            // Current element is greater than target,
            // so eliminate the current row
            else if(matrix[r][c] > target)
                r--;

            // Current element is smaller than target,
            // so eliminate the current column
            else
                c++;
        }

        // Target does not exist in the matrix
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 9;

    Solution obj;

    bool result = obj.searchMatrix(matrix, target);

    cout << (result ? "Target found" : "Target not found") << endl;

    return 0;
}