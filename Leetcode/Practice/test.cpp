#include<bits/stdc++.h>
using namespace std;

void findNum(vector<int>& cards, int m, vector<vector<int>> &com, vector<int> &s, int p) {
    if(m == 0) {
        com.push_back(s);
        return;
    }

    while(p < cards.size() && m-cards[p] >= 0) {
        s.push_back(cards[p]);
        findNum(cards, m-cards[p], com, s, p);
        p++;
        s.pop_back();
    }
}

vector<vector<int>> comSum(vector<int> &cards, int m) {
    sort(cards.begin(), cards.end());
    cards.erase(unique(cards.begin(), cards.end()), cards.end());
    vector<int> s;
    vector<vector<int>> com;
    findNum(cards, m, com, s, 0);
    return com;
}


int main() {
    vector<int> cards = {10, 30, 50};

    int m, n;
    cin >> n >> m;

    vector<vector<int>> com = comSum(cards, m);

    int count = 0;

    for(int i=0; i<com.size(); i++) {
        if(com[i].size() == n) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}