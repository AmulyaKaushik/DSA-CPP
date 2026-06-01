#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int,int> mpp;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mpp[x]++;
    }

    int maxFreq = 0;
    int minFreq = n;

    int maxEle, minEle;

    for(auto it : mpp) {
        if(it.second > maxFreq) {
            maxFreq = it.second;
            maxEle = it.first;
        }

        if(it.second < minFreq) {
            minFreq = it.second;
            minEle = it.first;
        }
    }

    cout << "Highest Frequency Element: " << maxEle << endl;
    cout << "Lowest Frequency Element: " << minEle << endl;

    return 0;
}