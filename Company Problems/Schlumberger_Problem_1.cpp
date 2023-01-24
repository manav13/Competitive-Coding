#include<bits/stdc++.h>
using namespace std;

void printString(vector<int> &debug, vector<char> &op) {
    cout << "0 ";
    for(int i=debug.size()-1; i>=0; i--) {
        cout << op[i] << " " << debug[i] << " ";
    }
    cout << endl;
}

void countHelper(string str, int target, int sum, int index, int &count, vector<int> &debug, vector<char> &op) {
    if(index < 0)
        return;

    string num = "";
    for(int i=index; i>=0; i--) {
        num = str[i] + num;
        int number = stoi(num);

        // debug.push_back(number);
        // op.push_back('+');

        if(sum + number == target && i == 0) {
            printString(debug, op);
            count++;
        }
        
        countHelper(str, target, sum+number, i-1, count, debug, op);

        
        // op.pop_back();
        // op.push_back('-');

        
        // if(sum - number == target && i == 0) {
        //     // printString(debug, op);
        // }
        countHelper(str, target, sum-number, i-1, count, debug, op);
        // op.pop_back();
        // debug.pop_back();
    }
}

int count(string str, int target) {
    int count = 0;
    vector<int> debug;
    vector<char> op;
    countHelper(str, target, 0, str.size()-1, count, debug, op);
    return count;
}

int main() {
    string str = "123456789";
    int target = 100;

    cout << count(str, target) << endl;
}