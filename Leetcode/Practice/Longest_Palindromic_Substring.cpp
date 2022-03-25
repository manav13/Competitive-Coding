#include<bits/stdc++.h>
using namespace std;

int findPalindrome(string s, int i1, int i2, int &index1, int &index2) {
    index1 = i1;
    index2 = i2;
    while((index1 >= 0 && index2 < s.size()) && (s[index1] == s[index2])){
        index1--;
        index2++;
    }
    index1++;
    index2--;
    return index2-index1+1;
}

string longestPalindrome(string s) {
    int size = s.size();
    int max = 0;
    string palindrome;
    for(int i=0; i<size; i++) {
        int left1, right1, left2, right2;
        int p1 = findPalindrome(s, i, i, left1, right1);
        int p2 = ( (i+1 < size && s[i] == s[i+1]) ? findPalindrome(s, i, i+1, left2, right2) : 0);

        if(p2 > p1) {
            left1 = left2;
            right1 = right2;
            p1 = p2;
        }
        if(p1 > max) {
            palindrome = s.substr(left1, p1);
            max = p1;
        }
    }
    return palindrome;
}

int main() {
    cout << longestPalindrome("abcdbbfcba") << endl;
    // string s = "babad";
    // cout << s.substr(0,2) << endl;
}