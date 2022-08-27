#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        unordered_map<char, char> hash;
        hash[')'] = '(';
        hash['}'] = '{';
        hash[']'] = '[';
        
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if(!st.empty() && hash[c] == st.top()) {
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
    return 0;
}