#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 1e9 + 7;

void solve() {
    /*
    (a[l] ... a[r]) (a[r + 1] ... a[k]) -> not the case
    no two consecutive subsegments
    */
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll> > dp(n, vector<ll> (k + 1, INT64_MAX));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            ll mn = a[i];
            for(int l = 0; l <= min(j, i); l++) {
                mn = min(mn, (ll)a[i - l]);
                dp[i][j] = min(dp[i][j], (i > l ? dp[i - l - 1][j - l] : 0) + mn * (l + 1));
            }
        }
    }
    cout << dp[n - 1][k] << "\n";
}

int main() {
    FAST
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

