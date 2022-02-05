// Name - Efficient Shipping 
// Leetcode ref - https://leetcode.com/problems/maximum-units-on-a-truck

#include<bits/stdc++.h>
using namespace std;

long getMaxUnits(vector<long> boxes, vector<long> unitsPerBox, long truckSize) {
    vector<vector<long>> B;
    long size = boxes.size();

    for(long i=0; i<size; i++) {
        vector<long> temp;
        temp.push_back(boxes[i]);
        temp.push_back(unitsPerBox[i]);
        B.push_back(temp);
    }

    sort(B.begin(), B.end(), [](auto& a, auto& b) { return b[1] < a[1];});
    long ans = 0;
    for (auto& b : B) {
        long count = min(b[0], truckSize);
        ans += count * b[1], truckSize -= count;
        if (!truckSize) return ans;
    }
    return ans;
}

int main() {
    return 0;
}