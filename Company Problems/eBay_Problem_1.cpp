#include<bits/stdc++.h>
using namespace std;

string solution(string text, vector<char> sticky) {
    int size = sticky.size();

    unordered_map<char, int> hash;
    for(int i=0; i<size; i++) {
        hash[sticky[i]]++;
        hash[toupper(sticky[i])]++;
    }

    int textSize = text.size();
    string output = text.substr(0,1);
    bool wasContinued = false;
    for(int i=1; i<textSize; i++) {
        if(text[i] == text[i-1] && hash.find(text[i]) != hash.end() && !wasContinued) {
            wasContinued = true;
            continue;
        }
        output += text[i];
        wasContinued = false;
    }
    return output;
}

int main() {
    int n;
    cin >> n;

    vector<char> sticky(n);
    for(int i=0; i<n; i++) {
        cin >> sticky[i];
    }

    cout << solution("LLLLenstra LLLLenstra LLLLovasz", sticky) << endl;
}