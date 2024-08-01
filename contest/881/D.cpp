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

int dfs(int cur, int prev, vector<vector<int> >& G, vector<int>& child) {
    int cnt = 0;
    for(int x : G[cur]) {
        if(x != prev) {
            cnt++;
            child[cur] += dfs(x, cur, G, child);
        }
    }
    if(cnt == 0) return child[cur] = 1;
    return child[cur];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<int> child(n + 1, 0);
    dfs(1, 1, G, child);
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << (ll)child[x] * (ll)child[y] << "\n";
    }
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
