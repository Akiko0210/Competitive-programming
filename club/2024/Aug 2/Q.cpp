#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<ll, ll>
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

void solve() {
    FAST
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > G(n + 1);

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c; 
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    vector<ll> cost(n + 1, 1e15), prev(n + 1, -1);
    vector<bool> vis(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    cost[1] = 0;

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(vis[cur.ss]) {
            // already visited before.
            continue;
        }

        //visiting for the first time.
        vis[cur.ss] = 1;
        if(cur.ss == n) break;

        for(pii edge : G[cur.ss]) {
            if(cost[edge.ff] > cur.ff + edge.ss) {
                prev[edge.ff] = cur.ss;
                cost[edge.ff] = cur.ff + edge.ss;
                pq.push({cost[edge.ff], edge.ff});
            }
        }
    }
    if(prev[n] == -1) {
        cout << "-1\n";
        return;
    }

    vector<int> path = {n};
    while(path.back() != 1) {
        path.pb(prev[path.back()]);
    }

    reverse(path.begin(), path.end());
    for(int x : path) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

