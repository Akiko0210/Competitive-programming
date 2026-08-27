#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define tii tuple<int, int, int>
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
    vector<tii> edges(m);
    vector<vector<int> > G(n + 1);
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
        G[b].pb(a);
    }

    auto reachableTo = [&] (int a) -> vector<bool> {
        vector<int> nodes = {a};
        vector<bool> vis(n + 1, false);
        vis[a] = true;
        for(int i = 0; i < nodes.size(); i++) {
            for(int next : G[nodes[i]]) {
                if(vis[next]) continue;

                vis[next] = true;
                nodes.pb(next);
            }
        }

        return vis;
    };

    vector<ll> dis(n + 1, -1e18);
    dis[1] = 0;
    auto toSink = reachableTo(n);

    auto relax_round = [&]() -> bool {
        bool changed = false;
        for(auto [a, b, c] : edges) {
            if(dis[a] == -1e18 || !toSink[b]) continue;
            
            if(dis[a] + c > dis[b]) {
                dis[b] = dis[a] + c;
                changed = true;
            }
        }
        return changed;
    };

    for(int i = 0; i < n; i++) {
        bool changed = relax_round();
        if(!changed) {
            break;
        }
        if(i == n - 1) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << dis[n] << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

