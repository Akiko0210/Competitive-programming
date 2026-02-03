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

unordered_map<int, unordered_map<int, int> > adj, temp;

int bfs(int start, vector<int>& prev) {
    queue<pii> q;
    q.push({start, INF});

    while(!q.empty()) {
        auto [cur, f] = q.front();
        q.pop();
        for(auto &[a, c] : adj[cur]) {
            if(prev[a] == -1 && c > 0) {
                prev[a] = cur;
                int newf = min(f, c);
                if(a == 0) {
                    return newf;
                }
                q.push({a, newf});
            }
        }
    }
    return 0;
}

int flow(int source, int sink) {
    vector<int> prev(source + 1, -1);
    int f, ans = 0;
    while(f = bfs(source, prev)) {
        // debug(f);
        ans += f;
        int cur = sink;
        while(source != cur) {
            // debug(cur);
            adj[prev[cur]][cur] -= f;
            adj[cur][prev[cur]] += f;

            cur = prev[cur];
        }
        prev = vector<int> (source + 1, -1);
    }
    return ans;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<pii> > G(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }

    vector<int> cars(c);
    for(int i = 0; i < c; i++) {
        cin >> cars[i];
        cars[i]--;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> cost(n, INF);
    vector<vector<int> > parents(n);
    cost[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [curcost, cur] = pq.top();
        pq.pop();

        if(cost[cur] != curcost) continue;

        for(auto &[x, xcost] : G[cur]) {
            if(cost[x] < curcost + xcost) continue;

            if(cost[x] > curcost + xcost) {
                parents[x].clear();
                cost[x] = curcost + xcost;
                pq.push({cost[x], x});
            }
            parents[x].pb(cur);
        }
    }

    for(int i = 0; i < n; i++) {
        // debug(i, cost[i]);
        for(int x : parents[i]) {
            // debug(x);
            adj[i][x]++;
        }
    }

    temp = adj;

    unordered_map<int, vector<int> > level;
    for(int x : cars) {
        level[cost[x]].pb(x);
    }

    int ans = 0;

    for(auto &[_, nodes] : level) {
        // debug(_);
        for(int x : nodes) {
            // debug(x);
            adj[n][x]++;
        }

        ans += flow(n, 0);
        adj = temp;
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

