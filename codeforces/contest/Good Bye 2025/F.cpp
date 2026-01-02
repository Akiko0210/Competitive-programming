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

const ll MOD = 998244353;

vector<int> sizes;

int dfs(int cur, int prev, vector<vector<int> >& G) {
    int size = 1;
    for(int x : G[cur]) {
        if(x != prev) {
            size += dfs(x, cur, G);
        }
    }
    if(size % 2 == 0 && cur != 0) {
        // white
        sizes.pb(size);
        return 0;
    }

    return size;
}

ll pw(ll a, ll b) {
    if(b == 1) return a;
    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) h = h * a % MOD;
    return h;
}

void solve() {
    int n;
    cin >> n;
    sizes.clear();
    vector<vector<int> > G(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    int extra = dfs(0, 0, G), sum = n - extra, m = sizes.size();
    ll p = 0, ans = 1, fac = 1;
    for(int i = 0; i < m; i++) {
        if(i < m - 1)
            fac = fac * (i + 1) % MOD;
        ans = ans * sizes[i] % MOD * sizes[i] % MOD;
        p = (p + pw(sizes[i], MOD - 2)) % MOD;
    }
    // debug(ans, extra, p);
    if(sizes.size() > 0) {
        ans = ans * extra % MOD * p % MOD * fac % MOD;
    }

    cout << ans << "\n";
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

