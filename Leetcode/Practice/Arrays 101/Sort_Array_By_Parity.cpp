#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    int length = A.size();
    int i = 0, j = 1;
    while(i<length && j<length) {
        if(i==j) j++;
        else if(A[i]%2==1 && A[j]%2==0) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j++;
        }
        else if(A[i]%2==0) i++;
        else if(A[j]%2==1) j++;
    }
    return A;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> a = sortArrayByParity(arr);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}