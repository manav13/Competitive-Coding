#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto p : s) {
            // if opening bracket then push the character else check top element and pop
            if(p == '(' || p == '{' || p == '[') {
                st.push(p);
            }
            else if(p == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
            else if(p == '}') {
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            }
            else if(p == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
    return 0;
}