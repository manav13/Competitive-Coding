// Name - reverse array queries

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int index1, int index2) {
    while(index1 < index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
        index1++;
        index2--;
    }
}

vector<int> compute(vector<int> arr, vector< vector<int> > operations) {
    // int size = arr.size();
    int numOfOp = operations.size();

    for(int i=0; i<numOfOp; i++) {
        reverseArray(arr, operations[i][0], operations[i][1]);
    }
    return arr;
}


int main() {
    int n, o;

    cin >> n >> o;
    vector<int> arr;
    vector< vector<int> > operations;

    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);

    }

    for(int i=0; i<o; i++) {
        int index1, index2;
        cin >> index1 >> index2;

        vector<int> op;
        op.push_back(index1);
        op.push_back(index2);
        operations.push_back(op);
    }

    vector<int> ans = compute(arr, operations);

    for(int i=0; i<n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}