#include<bits/stdc++.h>
using namespace std;

int findNumOfGroups(string seats) {
    int numGroups = 0;
    char prevSeat = seats[0];
    if(prevSeat == '1') ++numGroups;
    for(int i=1; i<seats.length(); i++) {
        if(seats[i] == '1') {
            if(prevSeat != '1') {
                ++numGroups;
            }
        }
        prevSeat = seats[i];
    }
    return numGroups;
}

int main() {
    int t;
    cin >> t;

    while(t) {
        string seats;
        cin >> seats;

        cout << findNumOfGroups(seats) << endl;
        
        --t;
    }

    return 0;
}