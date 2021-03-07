#include<bits/stdc++.h>
using namespace std;

int minimumLengthEncoding(vector<string>& words) {
    sort(words.begin(), words.end(), []
    (const string& first, const string& second){
        return first.size() > second.size();
    });
    int n = words.size();
    vector<int> indicies;
    string s = "";
    vector<int> posHash;
    for(auto word : words) {
        if(s == "") {
            s = s + word + "#";
            posHash.push_back(word.length());
            indicies.push_back(0);
        }
        else {
            int flag = 0;
            int wordSize = word.length();
            for(auto index : posHash) {
                int flag2 = 1;
                int spos = index - wordSize;
                for(int i = 0; i<wordSize; i++) {
                    if(word[i] != s[spos+i]) {
                        flag2 = 0;
                        break;
                    }
                }
                if(flag2 == 1) {
                    flag = 1;
                    indicies.push_back(spos);
                }
            }
            if(flag == 0) {
                indicies.push_back(s.length());
                s = s + word + "#";
                posHash.push_back(s.length() - 1);
            }
        }
    }
    // cout << s << endl;
    return s.length();
}

int main() {
    vector<string> words;
    int n;
    cin >> n;
    while(n) {
        string word;
        cin >> word;
        words.push_back(word);
        --n;
    }
    cout << minimumLengthEncoding(words) << endl;
    return 0;
}