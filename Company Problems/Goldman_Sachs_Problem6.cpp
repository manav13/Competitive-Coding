#include<bits/stdc++.h>
using namespace std;

int compute(vector<string> upRight) {
    int size = upRight.size();
    int minRow = (int) upRight[0][0], minCol = (int) upRight[0][2];
    for(int i=1; i<size; i++) {
        int row = (int) upRight[i][0];
        int col = (int) upRight[i][2];
        if(row < minRow) minRow = row;
        if(col < minCol) minCol = col;
    }
    return minRow*minCol;
}

int main() {
    int n;
    cin >> n;
    vector<string> vec;
    for(int i=0; i<n; i++) {
        string str;
        getline(cin, str);
        vec.push_back(str);
    }
    cout << compute(vec) << endl;
    return 0;
}