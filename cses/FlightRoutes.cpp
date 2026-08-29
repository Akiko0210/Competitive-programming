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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb({b, c});
    }

    vector<vector<ll> > cost(n + 1, vector<ll> (k, 1e18));
    cost[1][0] = 0;

    priority_queue<tii, vector<tii>, greater<>> pq;
    pq.push({0, 0, 1});

    while(!pq.empty()) {
        auto [curcost, stage, cur] = pq.top();
        pq.pop();

        if(curcost > cost[cur][stage]) {
            continue;
        }

        for(auto [nxt, nextcost] : G[cur]) {
            ll newcost = curcost + nextcost;
            for(int i = 0; i < k; i++) {
                if(newcost < cost[nxt][i]) {
                    // shift push
                    for(int j = k - 1; j > i; j--) {
                        if(cost[nxt][j] > cost[nxt][j - 1]) {
                            cost[nxt][j] = cost[nxt][j - 1];
                            pq.push({cost[nxt][j], j, nxt});
                        }
                    }
                    cost[nxt][i] = newcost;
                    pq.push({newcost, i, nxt});
                    break;
                }
            }
        }
    }

    for(int i = 0; i < k; i++) {
        cout << cost[n][i] << " ";
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

