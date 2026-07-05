#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}


int main() {
    fastIO();

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> caf(n);

    for (int i = 0; i < n; i++) {
        cin >> caf[i];
    }

    sort(caf.begin(), caf.end());
    
    double tot = log2((double)caf[n-1]/x);
    for (int i=0; i<n-1; i++) {
        tot += log2((double)(x+caf[i])/x);
    } 

    cout << fixed << setprecision(14) << tot << "\n";

    return 0;
}