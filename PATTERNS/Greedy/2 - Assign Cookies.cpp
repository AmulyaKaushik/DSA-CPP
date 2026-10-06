#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Sort the children's greed factors
        sort(g.begin(), g.end());

        // Sort the cookie sizes
        sort(s.begin(), s.end());

        int res = 0;
        int i = 0;
        int j = 0;

        // Try to satisfy each child using the smallest
        // cookie that is large enough
        while(i < g.size() && j < s.size()){

            // Current cookie can satisfy the current child
            if(s[j] >= g[i]){
                res++;
                i++;
                j++;
            }

            // Cookie is too small, so try the next cookie
            else{
                j++;
            }
        }

        return res;
    }
};

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    Solution obj;

    int result = obj.findContentChildren(g, s);

    cout << "Maximum children satisfied: " << result << endl;

    return 0;
}