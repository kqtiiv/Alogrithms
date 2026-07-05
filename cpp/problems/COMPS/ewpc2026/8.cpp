#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> cur; 

typedef vector<pair<int,int>> Round;


vector<Round> zipMerge(const vector<Round>& A, const vector<Round>& B) {
    vector<Round> out(max(A.size(), B.size()));
    for (size_t i = 0; i < out.size(); i++) {
        if (i < A.size()) out[i].insert(out[i].end(), A[i].begin(), A[i].end());
        if (i < B.size()) out[i].insert(out[i].end(), B[i].begin(), B[i].end());
    }
    return out;
}

vector<Round> binaryPartition(int lo, int hi, int threshold) {
    if (hi <= lo) return {};
    int mid = (lo + hi) / 2;
    vector<Round> left = binaryPartition(lo, mid, threshold);
    vector<Round> right = binaryPartition(mid + 1, hi, threshold);
    vector<Round> combined = zipMerge(left, right);

    int c = 0;
    for (int p = lo; p <= mid; p++) if (cur[p] <= threshold) c++;
    int d = 0;
    for (int p = mid + 1; p <= hi; p++) if (cur[p] <= threshold) d++;

    int l2 = lo + c, r2 = mid + d;
    if (l2 < r2) {
        reverse(cur.begin() + l2, cur.begin() + r2 + 1);
        combined.push_back({{l2, r2}});
    } else {
        combined.push_back({});
    }
    return combined;
}

vector<Round> sortRange(int lo, int hi) {
    if (hi <= lo) return {};
    int mid = (lo + hi) / 2;
    vector<Round> partRounds = binaryPartition(lo, hi, mid);
    vector<Round> rec = zipMerge(sortRange(lo, mid), sortRange(mid + 1, hi));
    vector<Round> result = partRounds;
    result.insert(result.end(), rec.begin(), rec.end());
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) { return a[x] < a[y]; });
    vector<int> rank(n);
    for (int r = 0; r < n; r++) rank[order[r]] = r;
    cur = rank;

    vector<Round> allRounds = sortRange(0, n - 1);

    vector<Round> rounds;
    for (auto &r : allRounds) if (!r.empty()) rounds.push_back(r);

    cout << rounds.size() << "\n";
    for (auto &rnd : rounds) {
        cout << rnd.size() << "\n";
        for (auto &pr : rnd) {
            cout << (pr.first + 1) << " " << (pr.second + 1) << "\n";
        }
    }

    return 0;
}