#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers, int pivot) {
    int size = numbers.size();
    vector<int> ans(size);
    for(int i=0; i<size; i++) {
        if(numbers[i] == 0) ans[i] = 0;
        else if ((numbers[i]<0 && pivot<0) || (numbers[i]>0 && pivot>0)) ans[i] = 1;
        else ans[i] = -1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int pivot;
    cin >> pivot;
    vector<int> ans = solution(arr, pivot);
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}