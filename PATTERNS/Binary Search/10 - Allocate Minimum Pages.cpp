#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int> &arr, int n, long long limit, int stud){

        // Start by assigning books to the first student
        int k = 1;
        long long pages = 0;

        for(int i = 0; i < n; i++){

            // Assign the current book if the page limit is not exceeded
            if(pages + arr[i] <= limit){
                pages += arr[i];
            }
            else{

                // Assign the current book to the next student
                k++;
                pages = arr[i];

                // Too many students are required
                if(k > stud)
                    return false;
            }
        }

        // All books can be allocated within the given limit
        return true;
    }

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        // Every student must receive at least one book
        if(n < k)
            return -1;

        long long low = 0;
        long long high = 0;

        for(int i = 0; i < n; i++){

            // Minimum limit must be at least the largest book
            low = max(low, (long long)arr[i]);

            // Maximum limit is the sum of all pages
            high += arr[i];
        }

        long long res = -1;

        while(low <= high){

            // Try the middle page limit
            long long guess = (low + high) / 2;

            // Check whether allocation is possible
            if(isValid(arr, n, guess, k)){
                res = guess;

                // Try to minimize the maximum pages assigned
                high = guess - 1;
            }
            else{

                // Limit is too small, so increase it
                low = guess + 1;
            }
        }

        return (int)res;
    }
};

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    Solution obj;

    int result = obj.findPages(arr, k);

    cout << "Minimum possible maximum pages: " << result << endl;

    return 0;
}