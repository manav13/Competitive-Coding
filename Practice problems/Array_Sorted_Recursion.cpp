#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int size) {
    if(size == 0 || size == 1) return true;
    if(a[0] > a[1]) {
        return false;
    }
    bool sorted = isSorted(a+1, size-1);
    return sorted;
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    cout << isSorted(a,n) << endl;
    return 0;
}