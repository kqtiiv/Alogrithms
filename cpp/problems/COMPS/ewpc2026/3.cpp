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
    cin >> n;

    vector<pair<ll, ll>> paintings(n);

    for (int i = 0; i < n; i++) {
        ll t, d, c;
        cin >> t >> d >> c;
        paintings[i] = {t + d, c};
    }
    
    sort(paintings.begin(), paintings.end());

    ll ans = 0;

    for (auto& [me, fr] : paintings) {
        ans = max(ans, me) + fr;
    }

    cout << ans << "\n";

    return 0;
}