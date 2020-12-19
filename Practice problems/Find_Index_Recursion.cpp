#include<bits/stdc++.h>
using namespace std;

int findFirstIndex(int a[], int size, int n) {
    if (size == 0) {
        return -1;
    }
    int ans;
    if (n == a[0]) {
        return 0;
    } else {
        ans = findFirstIndex(a+1, size-1, n);
        if (ans == -1) {
            return ans;
        } else {
            return ans + 1;
        }
    }
    return ans;
}

int findLastIndex(int a[], int size, int n) {
    if (size == 0) {
        return -1;
    }
    int ans;
    if (n == a[size]) {
        return size;
    } else {
        ans = findLastIndex(a, size-1, n);
        return ans;
    }
}

int findLastIndex2(int a[], int size, int n) {
    if (size == 0) {
        return -1;
    }
    int ans = findLastIndex2(a+1, size-1, n);
    if (ans == -1) {
        if (n == a[0]) {
            return 0;
        } else {
            return ans;
        }
    } else {
        return ans + 1;
    }
}

int findAllOccurence(int a[], int size, int n) {
    if (size == 0) {
        return 0;
    }
    int ans = findAllOccurence(a, size-1, n);
    return a[size-1] == n ? ans+1 : ans;
}

int main() {
    int a[5];
    int size = 5;
    for (int i=0; i<size; ++i) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    //cout << findFirstIndex(a, size, n) << endl;
    //cout << findLastIndex2(a, size, n) << endl;

    cout << findAllOccurence(a, size, n) << endl;

    return 0;
}