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

using tii = tuple<ll, int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2), l(n + 1, -1), r(n + 1);
    vector<pii> segs;
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
        if(l[a[i]] == -1) l[a[i]] = i;
        else {
            r[a[i]] = i;
            segs.pb({r[a[i]], l[a[i]]});
        }
        segs.pb({i, i});
    }

    sort(segs.begin(), segs.end());// by end
    vector<ll> dp(2 * n, 0);
    for(auto [r, l] : segs) {
        ll before = 0, len = r - l + 1;
        if(l > 0) before = dp[l - 1];
        dp[r] = max(dp[r], before + len * len);
    }

    cout << dp[2 * n - 1] << "\n";


    /*
    greedy <--- wrong it was dp & segments are never overlapping.
    */


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

