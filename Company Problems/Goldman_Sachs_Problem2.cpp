#include<bits/stdc++.h>
using namespace std;

// bool check(string str, int k, int size) {
//     for(int i=0; i<size-1; i++) {
//         int temp1, temp2;
//         temp1 = (int) str[i];
//         temp2 = (int) str[i+1];

//         if(abs(temp1-temp2)>k) return false;
//     }
//     return true;
// }

// string compute(int k, string str) {
//     int size = str.length();

//     for(int window=size; window>0; window--) {
//         int num = size-window+1;
//         for(int i=0; i<num; i++) {
//             bool isSubstring = check(str.substr(i, window), k, window);
//             if(isSubstring) return str.substr(i, window);
//         }
//     }
//     return str;
// }

string compute(int k, string word) {
    string max = "";
    string ans;
    int ansCount = 0;
    int size = word.size();
    int maxCount = 0;
    for(int i=0; i<size; i++) {
        int temp1 = (int) word[i];
        int temp2 = (int) word[i+1];

        if(abs(temp1-temp2)<=k) {
            maxCount++;
            max = max + word[i];
        }
        else {
            if(maxCount+1 > ansCount) {
                ans = max + word[i];
                ansCount = maxCount + 1;
            }
            max = "";
            maxCount = 0;
        }
    }
    return ans;
}

int main() {
    int k;
    string str;
    cin >> k;
    cin >> str;

    string ans = compute(k, str);
    cout << ans << endl;
    return 0;
}