#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define tii tuple<ll, int, int>
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
    // 1 to n shortest with 1 discount;
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
        // G[b].pb({a, c});
    }

    vector<vector<ll> > cost(n + 1, vector<ll> (2, 1e18));
    cost[1][0] = 0;
    priority_queue<tii, vector<tii>, greater<>> pq;
    pq.push({0, 0, 1});

    while(!pq.empty()) {
        auto [curcost, used, cur] = pq.top();
        pq.pop();

        if(curcost > cost[cur][used]) {
            continue;
        }

        // we can do early exit.
        if(cur == n && used == 1) break;

        for(auto [nxt, nxtcost] : G[cur]) {
            if(cost[nxt][used] > curcost + nxtcost) {
                cost[nxt][used] = curcost + nxtcost;
                pq.push({cost[nxt][used], used, nxt});
            }

            if(used == 0) {
                // can use the discount here
                int newcost = nxtcost / 2;
                if(cost[nxt][used + 1] > curcost + newcost) {
                    cost[nxt][used + 1] = curcost + newcost;
                    pq.push({cost[nxt][used + 1], used + 1, nxt});
                }
            }
        }
    }

    cout << cost[n][1] << "\n";
    

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

