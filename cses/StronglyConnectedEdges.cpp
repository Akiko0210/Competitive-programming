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

void dfs1(int cur, vector<vector<int> >& G, vector<bool>& vis, vector<int>& collection) {
    vis[cur] = true;
    for(int x : G[cur]) {
        if(!vis[x]) {
            dfs1(x, G, vis, collection);
        }
    }
    collection.pb(cur);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<pair<int, int> > edges;
    vector<int> vis(n + 1, -1);
    // -1 unvisited
    // 0 visiting
    // 1 visited

    auto dfs = [&](auto &&self, int cur, int prev) -> void {
        vis[cur] = 0;

        for(int x : G[cur]) {
            if(x == prev) continue;
            if(vis[x] == 0) {
                // connect back
                edges.pb({cur, x});
                continue;
            }
            if(vis[x] == 1) {
                // don't do anything.
            }
            if(vis[x] == -1) {
                // go to this edge and make sure it's connected.
                edges.pb({cur, x});
                self(self, x, cur);
            }
        }

        vis[cur] = 1;
    };

    for(int i = 1; i <= n; i++) {
        if(vis[i] == -1) dfs(dfs, i, i);
    }

    vector<vector<int> > newG(n + 1), newGT(n + 1);
    for(auto [a, b] : edges) {
        newG[a].pb(b);
        newGT[b].pb(a);
    }
    vector<bool> vis1(n + 1, false);
    vector<int> collection, components;
    for(int i = 1; i <= n; i++) {
        if(!vis1[i])
            dfs1(i, newG, vis1, collection);
    }
    
    vis1 = vector<bool> (n + 1, false);
    dfs1(collection.back(), newGT, vis1, components);
    if(components.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(auto [a, b] : edges) {
        cout << a << " " << b << "\n";
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

