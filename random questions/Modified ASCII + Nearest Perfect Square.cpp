#include <bits/stdc++.h>
using namespace std;

char nearestSquareChar(char c){
    int ascii = (int)c;                 //int -> ascii
    int root = sqrt(ascii);

    int lower = root*root;
    int upper = (root+1)*(root+1);

    int nearest;
    if((ascii-lower)<=(upper-ascii)){
        nearest = lower;
    }
    else{
        nearest = upper;
    }

    return (char)nearest;
}

int main() {
    string s = "RAGHAV";

    string ans = "";

    for(char c : s) {
        ans += nearestSquareChar(c);
    }

    cout << ans;
}