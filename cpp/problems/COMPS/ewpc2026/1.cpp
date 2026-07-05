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

    int need[5], has[5];
    for (int i = 0; i < 5; i++) cin >> need[i];
    for (int i = 0; i < 5; i++) cin >> has[i];
    
    int ans = INT_MAX;

    for (int i=0; i<5; i++) {
        if (need[i] == 0) continue;
        ans = min(ans, has[i]/need[i]);
    }

    cout << ans << "\n";

    return 0;
}