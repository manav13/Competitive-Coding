#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> s) {
    int size = s.size();
    int m = s[0].size();

    vector<int> result;
    int flag = 1;
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            for(int k=0; k<m; k++) {
                if(s[i][k] == s[j][k]) {
                    result.push_back(i);
                    result.push_back(j);
                    result.push_back(k);
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 0) break;
    }
    return result;
}

int main() {
    vector<string> s = {"abc", "bca", "dbe"};
    vector<int> result = solution(s);
    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}