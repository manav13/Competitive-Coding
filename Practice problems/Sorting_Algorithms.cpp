#include<bits/stdc++.h>
using namespace std;

void merge_array(int a[], int si, int ei) {
    int size = ei-si+1;
    int new_arr[size];

    int mid = int((si+ei)/2);
    int i = si;
    int j = mid+1;
    int count = 0;
    while(count != size) {
        if (j > ei) {
            new_arr[count] = a[i];
            i++;
        }
        else if (i > mid) {
            new_arr[count] = a[j];
            j++;
        }
        else {
            if (a[i] <= a[j]) {
                new_arr[count] = a[i];
                i++;
            } else {
                new_arr[count] = a[j];
                j++;
            }
        }
        count++;
    }
    count = 0;
    for (i = si; i<=ei; i++) {
        a[i] = new_arr[count];
        count++;
    }
    return;
}

void merge_sort(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = int((si+ei)/2);
    merge_sort(a, si, mid);
    merge_sort(a, mid+1, ei);

    merge_array(a, si, ei);
    return;
}

void swap(int a[], int index1, int index2) {
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
    return;
}

int partition(int a[], int si, int ei) {
    // Find appropriate position of a[si]
    int num_smaller_elements = 0;
    for (int i = si+1; i<=ei; i++) {
        if(a[i] < a[si]) {
            num_smaller_elements++;
        }
    }
    int pos = si+num_smaller_elements;
    swap(a, si, pos);

    // Arrange all smaller elements on left and larger elements on right
    int i = si;
    int j = ei;
    while(i!=pos && j!=pos) {
        if(a[i] < a[pos]) i++;
        else if (a[j] > a[pos]) j--;
        else if (a[i]>a[pos] && a[j]<a[pos]) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    return pos;
}

void quick_sort(int a[], int si, int ei) {
    // Base Case
    if (si >= ei) {
        return;
    }
    int index = partition(a, si, ei);
    // cout << index << endl;
    quick_sort(a, si, index-1);
    quick_sort(a, index+1, ei);
    return;
}

int main() {
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int *a = new int [size];
    cout << "Enter array elements:" << endl;
    for (int i=0; i<size; i++) {
        cin >> a[i];
    }
    //int a[size] = {7, 2, 9, 5, 6, 1, 4, 3, 10, 8};
    // merge_sort(a, 0, size-1);
    quick_sort(a, 0, size-1);
    cout << "Sorted array:" << endl;
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
    return 0;
}