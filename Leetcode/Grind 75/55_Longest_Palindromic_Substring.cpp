#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string palindrome(string s, int i, int size) {
        string s1 = "", s2 = "";
        int left = i, right = i;
        while(left>=0 && right<size) {
            if(s[left] == s[right]) {
                s1 += s[right];
                if(left != right)
                    s1 = s[left] + s1;
            }
            else break;
            left--;
            right++;
        }
        
        left = i;
        right = i+1;
        while(left>=0 && right<size) {
            if(s[left] == s[right]) {
                s2 += s[right];
                s2 = s[left] + s2;
            }
            else break;
            left--;
            right++;
        }
        cout << "s[i]: " << s[i] << " s1: " << s1 << " s2: " << s2 << endl;
        return (s1.size() > s2.size() ? s1 : s2);
    }
    
    string longestPalindrome(string s) {
        
        int size = s.size();
        int maxLen = 1;
        string maxStr = "";
        
        for(int i=0; i<size; i++) {
            string str = palindrome(s, i, size);
            if(str.size() >= maxLen) {
                maxStr = str;
                maxLen = str.size();
            }
        }
        return maxStr;
    }
};

int main() {
    return 0;
}