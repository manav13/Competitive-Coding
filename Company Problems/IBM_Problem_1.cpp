// Problem: Maximum Sum of Distinct Subarrays With Length K

#include<bits/stdc++.h>
using namespace std;

long findOptimalResouces(vector<int> arr, int k) {
    unordered_map<int, int> hash;
    long maxSum = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        hash[arr[i]]++;

        if (i >= k - 1){
            if (hash.size() == k) maxSum = max(maxSum, sum);
            sum -= arr[i - k + 1];
            if (--hash[arr[i - k + 1]] == 0) hash.erase(arr[i - k + 1]);
        }
    }
    return maxSum == 0 ? -1 : maxSum;
}

int main() {
    vector<int> arr = {1,3,3,1};
    int k = 3;

    cout << findOptimalResouces(arr, k) << endl;
}