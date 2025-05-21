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


vector<ll> dfs(ll cur, ll prev, vector<ll>& a, vector<vector<ll> >& G) {
    vector<ll> dp(20, 0);
    for(ll i = 0; i < 20; i++)
        dp[i] = a[cur] * i;
    
    for(ll x : G[cur]) {
        if(x != prev) {
            vector<ll> dp1 = dfs(x, cur, a, G);
            int mn1 = 19, mn2 = 19;
            for(int i = 0; i < 20; i++) {
                if(dp1[i] < dp1[mn1]) {
                    mn2 = mn1;
                    mn1 = i;
                    continue;
                }

                if(dp1[i] < dp1[mn2]) {
                    mn2 = i;
                }
            }

            for(int i = 0; i < 20; i++) {
                dp[i] += (i == mn1 ? dp1[mn2] : dp1[mn1]);
            }
            // debug(mn1, mn2, x);
        }
    }
    // debug(cur);
    // for(int i = 0; i < 10; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    return dp;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll &x : a) {
        cin >> x;
        sum += x;
    }

    vector<vector<ll> > G(n);
    for(int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<ll> ans = dfs(0, 0, a, G);
    ll mn = 1e18;
    for(ll x : ans) {
        mn = min(mn, x);
    }
    cout << sum + mn << "\n";

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

