#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i=0; i<k; i++) {
        int parity = 0;
        for (int j=0; j*k<n; j++) {
            if (s[i+j*k]=='1') parity++;
        }
        if (parity & 1) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

int main() {
    fastIO();

    ll t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}