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

    int n, k;
    cin >> n >> k;

    vector<ll> p(n);

    for (int i = 0; i < n; i++) cin >> p[i];
    
    ll ans = LLONG_MIN;

    for (int i=0; i<n-k; i++) {
        ans = max(ans, p[i+k]-p[i]);
    }

    cout << ans << "\n";

    return 0;
}