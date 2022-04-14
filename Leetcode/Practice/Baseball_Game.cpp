#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& ops) {
    int size = ops.size();
    vector<int> scores;
    int count = 0;
    for(int i=0; i<size; i++) {
        if(ops[i] == "+") {
            scores.push_back(scores[count-1] + scores[count-2]);
            count++;
        }
        else if(ops[i] == "D") {
            scores.push_back(2*scores[count-1]);
            count++;
        }
        else if(ops[i] == "C") {
            scores.pop_back();
            count--;
        }
        else {
            scores.push_back(stoi(ops[i]));
            count++;
        }
    }
    
    int sum = 0;
    for(auto sc : scores) {
        sum += sc;
    }
    return sum;
}

int main() {
    return 0;
}