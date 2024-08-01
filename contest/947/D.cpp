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

int dfs(int cur, int prev, vector<vector<int> >& jump, vector<vector<int> >& G, vector<int>& d) {
    jump[0][cur] = prev;
    d[cur] = d[prev] + 1;
    int ans = 0;
    for(int x : G[cur]) {
        if(x != prev) {
            ans += dfs(x, cur, jump, G, d) + 1;
        }
    }

    return ans + 1;
}

int LCA (int a, int b, vector<int>& d, vector<vector<int> >& jump) {
    if(d[a] > d[b]) {
        swap(a, b);
    }

    for(int i = 19; i >= 0; i--) {
        if((d[b] - d[a]) & (1 << i)) {
            b = jump[i][b];
        }
    }

    if(a == b) return a;

    for(int i = 19; i >= 0; i--) {
        if(jump[i][a] != jump[i][b]) {
            a = jump[i][a];
            b = jump[i][b];
        }
    }
    return jump[0][a];
}

int distance(int a, int b, vector<vector<int> > & jump, vector<int>& d) {
    int lca = LCA(a, b, d, jump);
    int dis = abs(d[lca] - d[a]) + abs(d[b] - d[lca]);
    return dis;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    vector<vector<int> > jump(20, vector<int> (n + 1));
    vector<int> d(n + 1);
    d[a] = 0;
    
    dfs(a, a, jump, G, d);
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    int lca = LCA(a, b, d, jump);

    if(d[a] < d[b]) {
        swap(a, b);
    }
    int dis = abs(d[lca] - d[a]) + abs(d[b] - d[lca]), ans = (dis + 1) / 2;
    dis = (dis + 1) / 2;

    for(int i = 19; i >= 0; i--) {
        if((1 << i) & dis) {
            a = jump[i][a];
        }
    }
    // debug(ans, dis, a);
    d[a] = 0;
    ans += dfs(a, a, jump, G, d) - 1;
    // debug(ans);
    int deepest = 0;
    for(int i = 1; i <= n; i++) {
        deepest = max(deepest, d[i]);
    }
    ans -= deepest - 1;


    // for(int i = 1; i <= n; i++) {
    //     deepest = max(d[i], deepest);
    // }
    // debug(ans);
    // ans -= deepest - 1;
    // debug(ans);

    // for(int i = 1; i < 20; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         jump[i][j] = jump[i - 1][jump[i - 1][j]];
    //     }
    // }

    // ans += distance(a, b, jump, d);
    // debug(ans);
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

