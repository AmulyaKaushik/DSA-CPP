#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> mpp;

    for(char ch : s) {
        mpp[ch]++;
    }

    int q;
    cin >> q;

    while(q--) {
        char c;
        cin >> c;

        cout << mpp[c] << endl;
    }

    return 0;
}