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
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
        // G[b].pb({a, c}); //one way
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<ll> cost(n + 1, 1e18);
    pq.push({0, 1});
    cost[1] = 0;

    while(!pq.empty()) {
        auto [c, cur] = pq.top();
        pq.pop();
        if(c > cost[cur]) {
            continue;
        }

        for(auto &[u, ucost] : G[cur]) {
            if(cost[u] > ucost + c) {
                cost[u] = ucost + c;
                pq.push({cost[u], u});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << cost[i] << " ";
    }
    cout << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

