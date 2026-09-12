#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "Amulya";
    unordered_map<char, int> f;
    for(auto c : s){
        f[c]++;
    }
    for(auto it : f){
        cout<<"Char "<<it.first<<" appears "<<it.second<<" times.";
    }
}