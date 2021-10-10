#include<bits/stdc++.h>
using namespace std;

int compute(vector<int> signalOne, vector<int> signalTwo) {
    int n = signalOne.size();
    int m = signalTwo.size();

    n = (n < m ? n : m);
    int max = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        if(signalOne[i] == signalTwo[i] && signalTwo[i] > max){
            count++;
            max = signalTwo[i];
        }
    }
    return count;
}

int main() {
    vector<int> signalOne;
    vector<int> signalTwo;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        signalOne.push_back(temp);
    }

    for(int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        signalTwo.push_back(temp);
    }

    cout << compute(signalOne, signalTwo) << endl;
    return 0;
}