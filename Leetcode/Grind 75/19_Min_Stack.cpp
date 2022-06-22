#include<bits/stdc++.h>
using namespace std;

// Using vector
class MinStack {
public:
    vector<int> st;
    int size = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        size++;
    }
    
    void pop() {
        st.pop_back();
        size--;
    }
    
    int top() {
        return st[size-1];
    }
    
    int getMin() {
        return st[min_element(st.begin(), st.end())-st.begin()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// Using two stacks
class MinStack {
public:
    stack<int> st, min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(min_st.top() == st.top()) {
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}