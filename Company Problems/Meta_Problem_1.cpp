#include<bits/stdc++.h>
using namespace std;

long long getLength(int num) {
    long long count = 0;
    while(num!=0) {
        count++;
        num = (int) num/10;
    } 
    return count;
}

vector<int> getAllCycles(int num) {
    long long len = getLength(num);
    vector<int> ans;
    ans.push_back(num);
    for(int i=0; i<len-1; i++) {
        int unit = num%10;
        num = (int) num/10;
        num = (unit*pow(10, len-1)) + num;
        ans.push_back(num);
    }
    return ans;
}

long long solution(vector<int> a) {
    sort(a.begin(), a.end());
    long long count = 0;
    // set<int> a_set(a.begin(), a.end());
    // vector<int> v(a_set.begin(), a_set.end());
    long long size = a.size();
    for(int i=0; i<size; i++) {
        vector<int> cycles = getAllCycles(a[i]);
        int sameEleCount = 0;
        for(auto ele : cycles) {
            if(binary_search(a.begin()+i+1, a.end(), ele)) {
                sameEleCount++;
                a.erase(remove(a.begin()+i+1, a.end(), ele), a.end());
                size--;
            }
        }
        // if(sameEleCount > 1) sameEleCount--;
        count += (sameEleCount*(sameEleCount+1))/2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << solution(a) << endl;
    return 0;
}