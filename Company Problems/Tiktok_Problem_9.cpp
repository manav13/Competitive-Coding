// Name - Town is disappearing

#include<bits/stdc++.h>
using namespace std;

int mysteriousTown(vector<int> household) {
    int size = household.size();
    int days = 1;
    while(size != 0) {
        vector<int> indexToBeRemoved;
        int removalSize = 0;
        for(int i=0; i<size; i++) {
            if(i == 0 && size > 1 && household[i] != household[i+1]) {
                indexToBeRemoved.push_back(i);
                removalSize++;
            }
            else if(i > 0 && i != size-1 && (household[i] != household[i+1] || household[i] != household[i-1])) {
                indexToBeRemoved.push_back(i);
                removalSize++;
            }

            else if(i == size-1 && household[i] != household[i-1]) {
                indexToBeRemoved.push_back(i);
                removalSize++;
            }
        }
        if(removalSize == 0)
            break;
        size -= removalSize;

        for(int i=removalSize-1; i>=0; i--) {
            household.erase(household.begin() + indexToBeRemoved[i]);
        }
        days++;
    }
    return days;
}

int main() {
    vector<int> households = {1,1,1};
    cout << mysteriousTown(households) << endl;

    return 0;
}