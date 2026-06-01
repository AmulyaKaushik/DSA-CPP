#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mpp[x]++;
    }

    int q;
    cin >> q;

    while(q--) {
        int num;
        cin >> num;

        cout << mpp[num] << endl;
    }

    return 0;
}