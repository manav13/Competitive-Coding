#include<bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> nums;
    int size = arr.size();
    
    for(int i=0; i<size; i++) {
        nums[arr[i]]++;
        int doubleNum = arr[i]*2;
        if(arr[i]==0 && nums[arr[i]]<=1) continue; 
        if(nums.find(doubleNum) != nums.end() || (arr[i]%2==0 && nums.find(int(arr[i]/2)) != nums.end())) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << checkIfExist(nums) << endl;
}