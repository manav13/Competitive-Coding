#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    
    int maxCandies = candyType.size()/2;

    unordered_set <int> uniqueCandies;
    for( auto it = candyType.begin(); it != candyType.end(); it++ ) {
        uniqueCandies.insert(*(it));
    }
    
    int size = uniqueCandies.size();

    return (maxCandies < size ? maxCandies : size);
}

int main() {
    // cout << distributeCandies() <<  endl;
    return 0;
}