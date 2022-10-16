#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1, false);
        dp[size] = true;
        
        for(int i=size-1; i>=0; i--) {
            
            for(auto word : wordDict) {
                int wordSize = word.size();
                if(i+wordSize <= size && s.substr(i, wordSize) == word) {
                    dp[i] = dp[i+wordSize];
                }
                
                if(dp[i])
                    break;
            }
            
        }
        return dp[0];
    }
};

int main() {
    return 0;
}