#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        // Store the number of $5 and $10 bills available
        int n = bills.size();
        int five = 0;
        int ten = 0;

        for(int i = 0; i < n; i++){

            int money = bills[i];

            // Customer gives $5, so no change is required
            if(money == 5){
                five++;
            }

            // Customer gives $10, so we need one $5 as change
            else if(money == 10){

                // No $5 bill available
                if(five == 0)
                    return false;

                five--;
                ten++;
            }

            // Customer gives $20, so we need $15 as change
            else{

                // Prefer using one $10 and one $5
                if(ten > 0){

                    if(five == 0)
                        return false;

                    ten--;
                    five--;
                }

                // Otherwise use three $5 bills
                else{

                    if(five < 3)
                        return false;

                    five -= 3;
                }
            }
        }

        // All customers received the correct change
        return true;
    }
};

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};

    Solution obj;

    bool result = obj.lemonadeChange(bills);

    cout << (result ? "Can provide change" : "Cannot provide change") << endl;

    return 0;
}