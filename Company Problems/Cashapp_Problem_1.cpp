#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> deck1, vector<int> deck2) {
    int size1 = deck1.size(), size2 = deck2.size();
    int ans = 0;

    while(!deck1.empty() && !deck2.empty()) {
        if(deck1[0] >= deck2[0]) {
            deck1.push_back(deck1[0]);
            deck1.push_back(deck2[0]);
        }
        else {
            deck2.push_back(deck2[0]);
            deck2.push_back(deck1[0]);
        }
        deck1.erase(deck1.begin());
        deck2.erase(deck2.begin());
        ans++;
    }
    return ans;
}

int main() {

    vector<int> deck1, deck2;
    int n1, n2;
    cin >> n1 >> n2;

    for(int i=0; i<n1; i++) {
        int temp;
        cin >> temp;
        deck1.push_back(temp);
    }

    for(int i=0; i<n2; i++) {
        int temp;
        cin >> temp;
        deck2.push_back(temp);
    }

    cout << solution(deck1, deck2) << endl;
    return 0;
}