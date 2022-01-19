#include<bits/stdc++.h>
using namespace std;

set<int> getPrimeFactors(int n) 
{
    set<int> primeFactors;
    while (n % 2 == 0) 
    {
        primeFactors.insert(2);
        n = n/2; 
    } 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    {
        while (n % i == 0) 
        {
            primeFactors.insert(i); 
            n = n/i; 
        } 
    }
    if (n > 2) primeFactors.insert(n);
    return primeFactors;
}

vector<int> lightBulbs(vector<int> states, vector<int> numbers) {
    int n = states.size();
    int m = numbers.size();

    for(int i=0; i<m; i++) {
        set<int> prime = getPrimeFactors(numbers[i]);
        // int numPrimes = prime.size();
        for(auto itr : prime) {
            int i = 1;
            while((itr*i) <= n) {
                states[(itr*i)-1] = (states[(itr*i)-1] == 0 ? 1 : 0);
                i++;
            }
        }
    }
    return states;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> states, numbers;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        states.push_back(temp);
    }

    for(int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    vector<int> res = lightBulbs(states, numbers);
    for(int i=0; i<n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}