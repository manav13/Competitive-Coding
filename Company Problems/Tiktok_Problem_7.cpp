// Name - Domino Tiling 3D
// Solution courtesy - Neel Patel
#include<bits/stdc++.h>
using namespace std;

vector<int> ways(vector<int> nvalues) {
    int size = nvalues.size();
    int maxN = *max_element(nvalues.begin(), nvalues.end());
    vector<long long int> f(maxN+1), g(maxN+1);

    f[0] = 1;
    g[0] = 0;
    f[1] = 2;
    g[1] = 1;

    for(long long int i=2; i<=maxN; i++) {
        g[i] = (g[i-1] + f[i-1])%(1000000009+7);
        f[i] = ((2*g[i]) + (2*g[i-1]) + f[i-2])%(1000000009+7);
    }

    vector<int> result(size);
    for(int i=0; i<size; i++) {
        result[i] = f[nvalues[i]];
    }
    return result;
}

int main() {
    int size;
    cin >> size;

    vector<int> nvalues(size);
    for(int i=0; i<size; i++) {
        cin >> nvalues[i];
    }

    vector<int> results = ways(nvalues);
    for(int i=0; i<size; i++) {
        cout << results[i] << endl;
    }
    return 0;
}