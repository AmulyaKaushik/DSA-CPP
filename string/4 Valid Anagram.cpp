#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(char ch : s){
            map1[ch]++;
        }

        for(char ch : t){
            map2[ch]++;
        }

        if(map1 == map2)
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(sol.isAnagram(s, t))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}