#include<bits/stdc++.h>
using namespace std;

double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

int main() {
    long long int t;
    cin >> t;
    double wr = 9.58;
    while(t) {
        double k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;
        double cr = 100/(k1*k2*k3*v);
        cout << (round(cr) < wr ? "YES" : "NO") << endl;
        --t;
    }
    return 0;
}