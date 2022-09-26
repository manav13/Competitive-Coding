// Problem Name = Get the Groups
#include <bits/stdc++.h>
using namespace std;

const int Mx = 1e5+5;
int par[Mx], cnt[Mx];
void ini(int n) {
    for(int i=1; i<=n; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
}

int root(int a) {
    if(a==par[a]) {
        return a;
    }
    return par[a] = root(par[a]);
}

void Union(int a, int b) {
    a = root(a);
    b = root(b);
    if(a==b) {
        return;
    }
    if(cnt[a] > cnt[b]) {
        swap(a,b);
    }
    par[a] = b;
    cnt[b] += cnt[a];
}

int* getTheGroups2(int n, int q, int sz, vector<string> queryType, vector<int> students1, vector<int> students2, int *ans) {
    ini(n);
    int current =  0;
    for(int i=0; i<q; i++) {
        if(queryType[i] == "Friend") {
            Union(students1[i], students2[i]);
        }
        else {
            int x = root(students1[i]), y = root(students2[i]);
            if(x == y) {
                ans[current++] = cnt[x];
            }
            else {
                ans[current++] = cnt[x] + cnt[y];
            }
        }
    }
    return ans;
}

vector<int> getTheGroups(int n, vector<string> queryType, vector<int> students1, vector<int> students2) {
    int q = queryType.size();
    int sz = 0;
    for(auto query : queryType) {
        if(query == "Total") {
            sz++;
        }
    }
    int ans[sz];
    int *ptr = getTheGroups2(n,q,sz,queryType, students1, students2, ans);
    vector<int> result;
    for(int i=0; i<sz; i++) {
        result.push_back(ptr[i]);
    }
    return result;
}