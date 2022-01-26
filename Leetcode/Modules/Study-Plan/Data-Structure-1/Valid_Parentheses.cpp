#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<int> stack;
    int size = s.size();
    for(int i=0; i<size; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        }
        else {
            if(!stack.empty()) {
                if(s[i] == ')' && stack.top() != '(') return false;
                else if(s[i] == '}' && stack.top() != '{') return false;
                else if(s[i] == ']' && stack.top() != '[') return false;
                else stack.pop();
            }
            else return false;
        }
    }
    if(!stack.empty()) return false;
    return true;
}

int main() {
    return 0;
}