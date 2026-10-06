#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        // Store value/weight ratio, value and weight for each item
        int n = val.size();
        vector<vector<double>> table;

        for(int i = 0; i < n; i++){

            // Calculate the value per unit weight
            table.push_back({
                (double)val[i] / wt[i],
                (double)val[i],
                (double)wt[i]
            });
        }

        // Sort items based on value/weight ratio
        sort(table.begin(), table.end());

        // Reverse to get the highest ratio first
        reverse(table.begin(), table.end());

        double res = 0;

        for(int i = 0; i < n; i++){

            // If the complete item can fit, take it completely
            if(table[i][2] <= capacity){
                capacity -= table[i][2];
                res += table[i][1];
            }

            // Otherwise, take only the fraction that fits
            else{
                res += (table[i][1] * capacity / table[i][2]);
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;

    double result = obj.fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value: " << result << endl;

    return 0;
}