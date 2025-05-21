#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF 1e18
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

const int N = 1e5;

vector<vector<int> > p(20, vector<int> (N, 0));
vector<vector<ll> > pdis(20, vector<ll> (N, 0));
vector<int> level(N, 0);
vector<vector<pii> > G(N);

void dfs(int cur, int prev) {
    for(pii el : G[cur]) {
        if(el.first != prev) {
            p[0][el.first] = cur;
            pdis[0][el.first] = el.second;
            level[el.first] = level[cur] + 1;
            dfs(el.first, cur);
        }
    }
}

int LCA(int a, int b) {
    if(level[a] < level[b]) {
        swap(a, b);
    }

    int diff = level[a] - level[b];
    for(int j = 0; j < 20; j++){
        if(diff & (1 << j)){
            a = p[j][a];
        }
    }

    if(a == b) return a;

    for(int j = 19; j >= 0; j--){
        if(p[j][a] != p[j][b]){
            a = p[j][a];
            b = p[j][b];
        }
    }

    return p[0][a];
}

ll linear_dis (int a, int lca) {
    ll adis = 0;
    for(int i = 19; i >= 0; i--) {
        if((level[lca] - level[a]) & (1 << i)) {
            adis += pdis[i][a];
            a = p[i][a];
        }
    }
    return adis;
}

ll dis(int a, int b) {
    int lca = LCA(a, b);
    return linear_dis(a, lca) + linear_dis(b, lca);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[v].pb({u, w});
        G[u].pb({v, w});
    }

    dfs(0, 0);

    for(int i = 1; i < 20; i++) {
        for(int j = 0; j < n; j++) {
            p[i][j] = p[i - 1][p[i - 1][j]];
            pdis[i][j] = pdis[i - 1][j] + pdis[i - 1][p[i - 1][j]];
        }
    }
    int k = *max_element(level.begin(), level.end());
    vector<vector<int> > nodes(k + 1);
    for(int i = 0; i < n; i++) {
        nodes[level[i]].pb(i);
    }

    vector<ll> dp(n, INF);
    for(int x : nodes[1]) {
        dp[x] = pdis[0][x];
    }

    for(int i = 2; i <= k; i++) {
        // cout << "level: " << i << "\n";
        for(int x : nodes[i]) {
            for(int y : nodes[i - 1]) {
                if(y == p[0][x]) continue;

                dp[x] = min(dp[x], dp[y] + dis(x, y));
                // cout << x << " from " << y << " is " << dp[x] << "\n";
            }
        }
    }
    ll ans = INF;
    for(int x : nodes[k]) {
        ans = min(ans, dp[x]);
    }

    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

