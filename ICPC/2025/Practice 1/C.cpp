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
    vector<ll> p(n + 1);
    vector<vector<pii> > G(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < m; i++) {
        int u, v, q;
        cin >> u >> v >> q;
        G[u].push_back({v, q});
        G[v].push_back({u, q});
    }

    vector<ll> best(n + 1, 1e18);
    vector<bool> vis(n + 1, false);
    best[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({0, 1});
    ll ans = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        ll cost = cur.first, node = cur.second;
        pq.pop();
        if(vis[node]) {
            continue;
        }
        // debug(node);
        ans += p[node] * cost;
        vis[node] = 1;
        for(auto e : G[node]) {
            int u = e.first, q = e.second;
            if(vis[u]) continue;
            if(q + cost < best[u]) {
                best[u] = q + cost;
                pq.push({best[u], u});
            }
        }
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

