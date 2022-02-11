// Name - ZigZag Array
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> arr) {
    int size = arr.size();
    int c1 = 0, c2 = 0;
    int flag = 1;
    // LHLH check
    for(int i=1; i<size; i++) {
        if(flag == 1 && arr[i] <= arr[i-1]) {
            c1++;
            arr[i] = -2;
        }
        if(flag == 0 && arr[i-1] != -2 && arr[i] >= arr[i-1]) {
            c1++;
            arr[i] = -1;
        }
       
        if(flag == 0) flag = 1;
        else flag = 0;
    }
    // cout << c1 << endl;
   
    flag = 0;
    // HLHL check
    for(int i=1; i<size; i++) {
        if(flag == 0 && arr[i-1] != -2 && arr[i] >= arr[i-1]) {
            c2++;
            arr[i] = -1;
        }
        if(flag == 1 && arr[i] <= arr[i-1]) {
            c2++;
            arr[i] = -2;
        }
       
        if(flag == 0) flag = 1;
        else flag = 0;
    }
    // cout << c2 << endl;
    return (c1 < c2 ? c1 : c2);
}

int main() {
    return 0;
}