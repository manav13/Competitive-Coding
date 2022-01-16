#include<bits/stdc++.h>
using namespace std;

int firstIndex(int a[], int size, int val) {
    //Base Case
    if(size == 0) return -1;
    if(a[0] == val) return 0;

    //Recursive call
    int index = firstIndex(a+1, size-1, val);

    //Calculation
    return (index==-1 ? index : index+1);
}

int lastIndex(int a[], int size, int val) {
    //Base Case
    if(size==0) return -1;
    if(a[size-1] == val) return size-1;

    //Recursive Call
    int index = lastIndex(a, size-1, val);

    //Calculation
    return index;

}

int main() {
    int size, val;
    cin >> size;
    int *arr = new int[size];
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    cin >> val;
    cout << "First Index: " << firstIndex(arr, size, val) << endl;
    cout << "Last Index: " << lastIndex(arr, size, val) << endl;
    return 0;
}