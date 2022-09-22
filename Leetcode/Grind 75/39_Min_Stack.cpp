#include<bits/stdc++.h>
using namespace std;

// Naive Approach
class MinStack {
public:
    stack<int> s1, s2, st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty())
            s1.push(val);
        else {
            while(!s1.empty() && s1.top() < val) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        st.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        while(s1.top() != val) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s1.top();
    }
};

// Optimal Way
class MinStack {
public:
    stack<int> st, minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minSt.push(val);
        }
        else {
            int curMin = minSt.top();
            if(val < curMin) {
                curMin = val;
            }
            minSt.push(curMin);
            st.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    return 0;
}