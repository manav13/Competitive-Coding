#include<bits/stdc++.h>
using namespace std;

string solution(int n, vector<string> operations) {
    string output = "";
    for(int i=0; i<n; i++) {
        output += '0';
    }
    int zeroIndex = 0;
    for(auto op : operations) {
        if(op == "L") {
            output[zeroIndex] = '1';
            zeroIndex++;
            while(output[zeroIndex] != '0') {
                zeroIndex++;
            }
        }
        else {
            int index = stoi(op.substr(1));
            output[index] = '0';

            if(index < zeroIndex) {
                zeroIndex = index;
            }
        }
    }
    return output;
}

int main() {
    int n, nOp;
    cin >> n >> nOp;
    vector<string> operations(nOp);

    for(int i=0; i<nOp; i++) {
        cin >> operations[i];
    }

    cout << solution(n, operations) << endl;
    return 0;
}