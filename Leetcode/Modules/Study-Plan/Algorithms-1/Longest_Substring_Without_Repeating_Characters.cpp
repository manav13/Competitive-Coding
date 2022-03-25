#include<bits/stdc++.h>
using namespace std;

// Old way
// int lengthOfLongestSubstring(string s) {
//     if(s.size() == 0) return 0;
    
//     int startIndex = 0, curIndex, ans = 1, curCount = 1;
//     unordered_map<char, pair<int, int>> hash;
    
//     hash[s[0]].first++;
//     hash[s[0]].second = 0;

//     for(curIndex = 1; curIndex < s.size(); curIndex++) {
//         if(hash.find(s[curIndex]) != hash.end()) {
//             if(s[curIndex] == s[startIndex]) {
//                 startIndex++;
//                 hash[s[curIndex]].second = curIndex;
//             }
//             else {

//                 if(curCount > ans) ans = curCount;
//                 int tempStart = hash[s[curIndex]].second + 1;
//                 // update hash map
//                 hash.clear();
//                 curCount = curIndex - tempStart + 1;
//                 for(int j = curIndex; j>=tempStart; j--) {
//                     hash[s[j]].first++;
//                     hash[s[j]].second = j;
//                 }
                
//                 startIndex = tempStart;
//             }
//         } else {
//             hash[s[curIndex]].first++;
//             hash[s[curIndex]].second = curIndex;
//             curCount++;
//         }
//     }
//     ans = curCount > ans ? curCount : ans;
//     return ans;
// }

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if(size == 0 || size == 1) return size;
    
    set<char> charSet;
    int left = 0, right = 0, ans = 0;
    for(; right<size; right++) {
        if(charSet.find(s[right]) != charSet.end()) {
            while(charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
        }
        charSet.insert(s[right]);
        ans = max(ans, right-left+1);
    }
    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}