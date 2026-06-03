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
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    unordered_map<double, double> dp;
    dp[1] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;

        auto nxt = dp;
        for(auto [s, val] : dp) {
            double nxt_s = s * (1 - (double)a[i].ss / 100);
            nxt[nxt_s] = max(nxt[nxt_s], val + s * a[i].ff);
            // debug(nxt_s, nxt[nxt_s]);
        }
        dp = nxt;
    }
    double mx = 0;
    for(auto [k, val] : dp) {
        mx = max(mx, val);
    }
    cout << fixed << setprecision(9) << mx << "\n";

}

int main() {
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

