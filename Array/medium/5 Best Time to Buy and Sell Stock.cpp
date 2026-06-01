#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profit = 0;
        int cost;

        for(int i = 1; i < prices.size(); i++) {
            cost = prices[i] - minimum;
            profit = max(profit, cost);
            minimum = min(minimum, prices[i]);
        }

        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution obj;
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;

    return 0;
}