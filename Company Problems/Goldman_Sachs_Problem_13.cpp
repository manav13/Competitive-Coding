// Question: Word Compression
#include<bits/stdc++.h>
using namespace std;

string compressWord(string word, int k) {
    int i=0, size = word.size();
    vector<int> countArr(size);
    for(int j=0; j<size; ++j, ++i) {
        word[i] = word[j];
        countArr[i] = i>0 && word[i-1] == word[j] ? countArr[i-1]+1 : 1;
        if(countArr[i] == k) i -= k;
    }
    return word.substr(0, i);
}

int main() {
    return 0;
}