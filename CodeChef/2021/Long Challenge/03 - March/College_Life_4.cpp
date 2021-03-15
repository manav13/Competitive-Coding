#include<bits/stdc++.h>
using namespace std;

// Similar to Minimum Coins problem

// omelette, milkshake, cake = 0, 1, 2
pair<int, int> getIngredients(int item) {
    switch (item)
    {
        case 0: return {2, 0};
        case 1: return {0, 3};
        case 2: return {1, 1};
    }
    return {0, 0};
}

int findPrice(int n, int curItem, pair<int, int>& ing, vector<int>& itemPrice) {
    int p1 = -1, p2 = -1;
    if(n==0) {
        return 0;
    }
    else if(curItem > 2) return -1;
    else {
        pair<int, int> ingNeeded = getIngredients(curItem);
        if(ingNeeded.first <= ing.first && ingNeeded.second <= ing.second) {

            ing.first -= ingNeeded.first;
            ing.second -= ingNeeded.second;

            p1 = findPrice(n-1, curItem, ing, itemPrice);
            if(p1 != -1) p1 += itemPrice[curItem];

            ing.first += ingNeeded.first;
            ing.second += ingNeeded.second;

            p2 = findPrice(n, curItem+1, ing, itemPrice);
            if(p2 == -1) return p1;
            else if (p1 == -1) return p2;
            return (p1 < p2 ? p1 : p2);
        }
        else {
            p2 = findPrice(n, curItem+1, ing, itemPrice);
            return p2;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t) {
        int n, price=0;
        vector<int> itemPrice(3);
        pair<int, int> ing;
        cin >> n >> ing.first >> ing.second >> itemPrice[0] >> itemPrice[1] >> itemPrice[2];
        vector<int> a, result;

        price = findPrice(n, 0, ing, itemPrice);
        // findPrice(n, 0, ing, itemPrice, a, result);
        // cout << (result.size()==0 ? -1 : result[0]) << endl;
        cout << price << endl;
        --t;
    }
    return 0;
}

// int getBill(vector<int> a, vector<int> itemPrice) {
//     int p = 0;
//     for(auto it : a) {
//         p += itemPrice[it];
//     }
//     return p;
// }

// void findPrice(int n, int curItem, pair<int, int>& ing, vector<int>& itemPrice, vector<int>& a, vector<int>& result) {
//     if(n==0) {
//         int p = getBill(a, itemPrice);
//         if(result.size() == 0) {
//             result.push_back(p);
//             return;
//         }
//         else {
//             if(p < result[0]) {
//                 result[0] = p;
//                 return;
//             }
//         }
//     }
//     else if(curItem > 2) return;
//     else {
//         pair<int, int> ingNeeded = getIngredients(curItem);
//         if(ingNeeded.first <= ing.first && ingNeeded.second <= ing.second) {
//             a.push_back(curItem);
//             ing.first -= ingNeeded.first;
//             ing.second -= ingNeeded.second;
//             findPrice(n-1, curItem, ing, itemPrice, a, result);
//             a.pop_back();
//             ing.first += ingNeeded.first;
//             ing.second += ingNeeded.second;
//         }
//         findPrice(n, curItem+1, ing, itemPrice, a, result);
//     }
// }