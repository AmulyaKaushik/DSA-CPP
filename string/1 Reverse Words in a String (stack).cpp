#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        
        for(char c : s){
            if(c != ' '){
                temp = temp + c;
            }
            else{
                if(!temp.empty()){
                    st.push(temp);
                    temp = "";
                }
            }
        }

        if(!temp.empty()){
            st.push(temp);
        }

        string ans = st.top();
        st.pop();

        while(!st.empty()){
            ans = ans + ' ' + st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    getline(cin, s);

    cout << obj.reverseWords(s) << endl;

    return 0;
}