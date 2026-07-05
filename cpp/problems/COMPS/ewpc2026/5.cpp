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

    vector<ll> nerv(n);

    for (int i = 0; i < n; i++) {
        cin >> nerv[i];
    }

    vector<int> diff(n-1);
    for (int i=0; i<n-1; i++) {
        diff[i] = nerv[i+1] - nerv[i];
        if (diff[i] < -1 || diff[i] > 1) {cout << "impossible\n"; return 0;}
    }

    vector<int> dir(n, -1); // -1 for not set, 0 for <, 1 for >
    bool ok = true;

    auto setDir = [&](int i, int v) {
        if (dir[i] == -1) dir[i] = v;
        else if (dir[i] != v) ok = false;
    };

    for (int i=0; i<n-1 && ok; i++) {
        if (diff[i] == 1) { setDir(i, 1); setDir(i+1, 1); }
        else if (diff[i] == -1) { setDir(i, 0); setDir(i+1, 0); }
    }

    for (int i=0; i<n-1 && ok; i++) {
        if (diff[i] == 0 && dir[i] != -1) {
            setDir(i+1, 1-dir[i]);
        }
    }

    for (int i=n-2; i>=0; i--) {
        if (diff[i] == 0 && dir[i+1] != -1) {
            setDir(i, 1-dir[i+1]);
        }
    }

    auto simulate = [&](vector<int>& dir) {
        vector<ll> res(n, 0);
        int r = 0, l = 0;
        for (int i=0; i<n; i++) { res[i] += r; if (dir[i]) r++; }
        for (int i=n-1; i>=0; i--) { res[i] += l; if (!dir[i]) l++; }
        return res;
    };

    bool unfinished = false;
    for (int i=0; i<n; i++) if (dir[i]==-1) unfinished = true;

    vector<int> ans;
    if (ok && !unfinished) ans = dir;
    else if (ok) {
        vector<int> case1(n), case2(n);
        case1[0] = 0; case2[0] = 1;
        for (int i=1; i<n; i++) {
            case1[i] = 1-case1[i-1];
            case2[i] = 1-case2[i-1];
        }
        if (simulate(case1) == nerv) ans = case1;
        else if (simulate(case2) == nerv) ans = case2;
        else ok = false;
    }

    if (ok && simulate(ans) != nerv) ok = false;

    if (!ok) cout << "impossible\n";
    else {
        cout << "possible\n";
        for (int d: ans) cout << ((d) ? '>' : '<');
        cout << "\n";
    }
    

    return 0;
}