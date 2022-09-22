#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        int left = 0, right = 1, spaceIndex = 0;
        int size = s.size();
        while(right < size) {
            while(right < size && s[right] != ' ') {
                right++;
            }
            spaceIndex = right;
            right--;

            // Reverse the word
            while(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            left = spaceIndex+1;
            right = spaceIndex+2;
        }
        return s;
    }
int main() {
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
    return 0;
}