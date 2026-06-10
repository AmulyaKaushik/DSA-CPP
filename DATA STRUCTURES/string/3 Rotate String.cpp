#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string rotateleft(string &s){
        string sub = s.substr(1, s.size() - 1);
        sub = sub + s[0];
        return sub;
    }

    bool rotateString(string s, string goal) {
        int n = s.size() - 1;

        for(int i = 0; i <= n; i++) {
            if(s == goal)
                return true;

            s = rotateleft(s);
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s, goal;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    if(sol.rotateString(s, goal))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}