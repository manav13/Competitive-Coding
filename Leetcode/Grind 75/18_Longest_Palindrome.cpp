#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for(auto c : s) {
            hash[c]++;
        }
        int numOfRepeatingChar = 0;
        bool isOddChar = false;
        for(auto it : hash) {
            if(it.second%2 == 0)
                numOfRepeatingChar += (it.second/2);
            else {
                isOddChar = true;
                numOfRepeatingChar += (it.second/2);
            }
        }
        int ans = numOfRepeatingChar*2;
        if(isOddChar) ans+=1;
        return ans;
    }
};

int main() {
    return 0;
}