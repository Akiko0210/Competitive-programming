#include <bits/stdc++.h>
using namespace std;

// Classic strange-printer DP on a compressed sequence.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Add sentinel zeros at both ends.
    vector<long long> v;
    v.reserve(n + 2);
    v.push_back(0);
    for (int i = 0; i < n; ++i) v.push_back(a[i]);
    v.push_back(0);

    // Compress consecutive duplicates.
    vector<long long> b;
    b.reserve(v.size());
    for (long long x : v) {
        if (b.empty() || b.back() != x) b.push_back(x);
    }
    int m = (int)b.size();

    // Strange printer DP on b[0..m-1]
    static int dp[805][805];
    for (int i = 0; i < m; ++i) dp[i][i] = 1;
    for (int len = 2; len <= m; ++len) {
        for (int l = 0; l + len - 1 < m; ++l) {
            int r = l + len - 1;
            int best = dp[l][r - 1] + 1;
            for (int k = l; k < r; ++k) {
                if (b[k] == b[r]) {
                    int cand = dp[l][k] + (k + 1 <= r - 1 ? dp[k + 1][r - 1] : 0);
                    best = min(best, cand);
                }
            }
            dp[l][r] = best;
        }
    }

    // Subtract 1 to remove the "free" background zero layer.
    cout << dp[0][m - 1] - 1 << '\n';
    return 0;
}
