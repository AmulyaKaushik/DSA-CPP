#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Find the number of rows and columns
        int nrow = matrix.size();
        int ncol = matrix[0].size();

        // Treat the 2D matrix as a 1D sorted array
        int n = nrow * ncol;

        int low = 0;
        int high = n - 1;

        while(low <= high){

            // Find the middle index
            int guess = (low + high) / 2;

            // Convert the 1D index into 2D row and column
            int r = guess / ncol;
            int c = guess % ncol;

            // Target found
            if(matrix[r][c] == target)
                return true;

            // Search in the right half
            else if(matrix[r][c] < target)
                low = guess + 1;

            // Search in the left half
            else
                high = guess - 1;
        }

        // Target does not exist
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