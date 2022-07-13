#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int performOperation(int op1, int op2, string t) {
        if(t == "+")
            return op1+op2;
        if(t == "-")
            return op1-op2;
        if(t == "*")
            return op1*op2;
        if(t == "/")
            return op1/op2;
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans;
        for(auto t : tokens) {
            if(t=="+" || t=="-" || t=="*" || t=="/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                int result = performOperation(op1, op2, t);
                st.push(result);
                ans = result;
            }
            else st.push(stoi(t));
        }
        if(!st.empty()) return st.top();
        return ans;
    }
};

int main() {
    return 0;
}