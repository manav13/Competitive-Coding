#include<bits/stdc++.h>
using namespace std;

pair<long long int, long long int> getIngredients(long long int item) {
    switch (item)
    {
        case 1: return {2, 0};
        case 2: return {0, 3};
        case 3: return {1, 1};
    }
    return {0, 0};
}

int main() {
    long long int t;
    cin >> t;
    while(t) {
        long long int n;
        pair<long long int, long long int> totalIng;
        // vector<pair<long long int, long long int> > price = {
        //     {1,0},
        //     {2,0},
        //     {3,0}
        // };
        vector<int> price(4);
        price[0] = 0;
        cin >> n >> totalIng.first >> totalIng.second >> price[1] >> price[2] >> price[3];

        // sort(price.begin(), price.end(), [] 
        // (pair<long long int, long long int>& p1, pair<long long int, long long int>& p2) {
        //     return p1.second > p2.second;
        // });
        // price.insert(price.begin(), {0,0});

        vector< vector<long long int> > k(4, vector<long long int>(n+1));
        vector< vector<long long int> > eggs(4, vector<long long int>(n+1));
        vector< vector<long long int> > bars(4, vector<long long int>(n+1));

        for(long long int i=0; i<=3; i++) {
            long long int E = totalIng.first;
            long long int B = totalIng.second;

            long long int curItem = i;
            for(long long int j=0; j<=n; j++) {
                if(i == 0 || j==0) {
                    k[i][j] = 0;
                    eggs[i][j] = 0;
                    bars[i][j] = 0;
                }
                else if(i==1) {
                    pair<long long int, long long int> ingNeed = getIngredients(curItem);
                    if(E >= ingNeed.first && B >= ingNeed.second) {
                        k[i][j] = k[i][j-1] + price[curItem];
                        eggs[i][j] = ingNeed.first;
                        bars[i][j] = ingNeed.second;
                        E -= eggs[i][j];
                        B -= bars[i][j];
                    }
                    else {
                        k[i][j] = -1;
                        eggs[i][j] = 0;
                        bars[i][j] = 0;
                    }
                }
                else {
                    pair<long long int, long long int> ingNeed = getIngredients(curItem);
                    if(E >= ingNeed.first && B >= ingNeed.second) {
                        long long int p1 = k[i][j-1] + price[curItem];
                        long long int p2 = k[i-1][j];
                        if(p2 == -1) {
                            k[i][j] = p1;
                            eggs[i][j] = ingNeed.first;
                            bars[i][j] = ingNeed.second;
                            E -= eggs[i][j];
                            B -= bars[i][j];
                        }
                        else {
                            if(p1 < p2) {
                                k[i][j] = p1;
                                eggs[i][j] = ingNeed.first;
                                bars[i][j] = ingNeed.second;
                                E -= eggs[i][j];
                                B -= bars[i][j];
                            }
                            else {
                                k[i][j] = p2;
                                eggs[i][j] = eggs[i-1][j];
                                bars[i][j] = bars[i-1][j];
                                E -= eggs[i][j];
                                B -= bars[i][j];
                            }
                        }
                    }
                    else {
                        k[i][j] = k[i-1][j];
                        eggs[i][j] = eggs[i-1][j];
                        bars[i][j] = bars[i-1][j];
                        E -= eggs[i][j];
                        B -= bars[i][j];
                    }
                }
            }
        }
        cout << k[3][n] << endl;
        --t;
    }
    return 0;
}