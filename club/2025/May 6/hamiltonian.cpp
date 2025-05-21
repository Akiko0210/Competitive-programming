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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
    }

    vector dp(1 << (n), vector (n, 0));
    dp[1][0] = 1;
    
    for(int mask = 1; mask < (1 << n) - 1; mask++) {
        // hasn't visit first city or already visited last city.
        if(!(mask & 1) || (mask & (1 << (n - 1)))) continue;
    
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                // from i, move to the others.
                for(int x : G[i]) {
                    if(!(mask & (1 << x))) {
                        (dp[mask ^ (1 << x)][x] += dp[mask][i]) %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

