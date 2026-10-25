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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[v].pb(u);
        G[u].pb(v);
    }

    vector<int> dis(n, -1);
    dis[n - 1] = 0;
    queue<int> q;
    q.push(n - 1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == 0) continue;

        for(int x : G[cur]) {
            if(dis[x] == -1) {
                dis[x] = dis[cur] + 1;
                q.push(x);
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     cout << dis[i] << " ";
    // }
    // cout << "\n";
    int ans = dis[0];
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        ans = max(ans, dis[x] + 1);
    }

    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
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

