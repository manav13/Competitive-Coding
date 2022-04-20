#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while(start<=end) {
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void solve(string s, int index, int size, vector<vector<string>>& output, vector<string>& ds) {
    if(index==size) {
        output.push_back(ds);
        return;
    }
    
    for(int i=index; i<size; i++) {
        if(isPalindrome(s, index, i)) {
            ds.push_back(s.substr(index, i-index+1));
            solve(s, i+1, size, output, ds);
            ds.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> output;
    vector<string> ds;
    int size = s.size();
    solve(s, 0, size, output, ds);
    return output;
}

int main() {
    return 0;
}