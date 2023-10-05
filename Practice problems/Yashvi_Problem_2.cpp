#include<bits/stdc++.h>
using namespace std;

vector<long> substitutions(vector<string> words, vector<string> phrases) {
    unordered_map<string, long> hash;

    for(auto word : words) {
        string s = sort(word.begin(), word.end());
        hash[s]++;
    }

    vector<long> ans;

    for(auto phrase : phrases) {
        long m = 1;

        for(auto word : phrase) {
            string str = sort(word.begin(), word.end());
            if(hash.find(str) != hash.end()) {
                m = m*hash[str];
            }
        }
        ans.push_back(m);
    }

    return ans;
}

int main() {
    vector<string> words = {"desserts", "stressed", "bats", "stabs", "are", "not"};
    vector<string> phrases = {"bats are not stressed"};

    vector<long> ans = substitutions(words, phrases);
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}