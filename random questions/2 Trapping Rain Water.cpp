#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h) {
    int n = h.size();

    vector<int> prefixmax(n);
    vector<int> suffixmax(n);

    // Build prefix max
    prefixmax[0] = h[0];
    for(int i = 1; i < n; i++) {
        prefixmax[i] = max(prefixmax[i-1], h[i]);
    }

    // Build suffix max
    suffixmax[n-1] = h[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffixmax[i] = max(suffixmax[i+1], h[i]);
    }

    int total = 0;

    for(int i = 0; i < n; i++) {
        total += min(prefixmax[i], suffixmax[i]) - h[i];
    }

    return total;
}

int main() {
    vector<int> h = {4,2,0,3,2,5};

    cout << trap(h);

    return 0;
}