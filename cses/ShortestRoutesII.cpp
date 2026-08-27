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

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    // vector<vector<pii> > G(n + 1);
    vector<vector<ll> > dis(n + 1, vector<ll> (n + 1, 1e18));
    for(int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[a][b], c);
        // G[a].pb({b, c});
        // G[b].pb({a, c});
    }


    // auto djikstra = [&] (int source) {
    //     priority_queue<pii, vector<pii>, greater<>> pq;
    //     pq.push({0, source});
    //     dis[source][source] = 0;
    //     while(!pq.empty()) {
    //         auto [w, cur] = pq.top();
    //         pq.pop();

    //         if(w > dis[source][cur]) continue;

    //         for(auto &[nxt, cost] : G[cur]) {
    //             ll newdis = cost + w;
    //             if(dis[source][nxt] > newdis) {
    //                 dis[source][nxt] = newdis;
    //                 pq.push({newdis, nxt});
    //             }
    //         }
    //     }
    // };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(dis[j][i] + dis[i][k] < dis[j][k]) {
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }
        }
        // djikstra(i);
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (dis[a][b] == 1e18 ? -1 : dis[a][b]) << "\n";
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

