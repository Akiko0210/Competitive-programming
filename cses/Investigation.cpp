#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<ll, int>
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
    }
    // 
    vector<ll> mnFlight(n + 1, -1), mxFlight(n + 1, -1), cnt(n + 1, 0), cost(n + 1, 1e18);
    priority_queue<pii, vector<pii>, greater<>> pq;
    mnFlight[1] = 0;
    mxFlight[1] = 0;
    cnt[1] = 1;
    cost[1] = 0;

    pq.push({0, 1});
    while(!pq.empty()) {
        auto [curcost, cur] = pq.top();
        pq.pop();

        if(curcost > cost[cur]) continue;

        if(cur == n) {
            cout << cost[n] << " " << cnt[n] << " " << mnFlight[n] << " " << mxFlight[n] << "\n";
            return 0;
        }

        for(auto [nxt, nxtcost] : G[cur]) {
            ll newcost = nxtcost + curcost;
            if(newcost < cost[nxt]) {
                cost[nxt] = newcost;
                mnFlight[nxt] = mnFlight[cur] + 1;
                mxFlight[nxt] = mxFlight[cur] + 1;
                cnt[nxt] = cnt[cur];
                pq.push({newcost, nxt});
            } else if(newcost == cost[nxt]) {
                mnFlight[nxt] = min(mnFlight[nxt], mnFlight[cur] + 1);
                mxFlight[nxt] = max(mxFlight[nxt], mxFlight[cur] + 1);
                cnt[nxt] = (cnt[nxt] + cnt[cur]) % MOD;
            }
        }
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

