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

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<vector<int> > G(n + 1);

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    auto bfs = [&](int cur, vector<int>& dp) {
        queue<int> q;
        q.push(cur);
        dp[cur] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int x : G[cur]) {
                if(dp[x] == -1) {
                    dp[x] = dp[cur] + 1;
                    q.push(x);
                }
            }
        }
    };

    vector<int> d(n + 1, -1);
    bfs(1, d);

    int u = 0, mx = 0;
    for(int x : a) {
        if(d[x] > mx) {
            u = x;
            mx = d[x];
        }
    }

    vector<int> d1(n + 1, -1);
    bfs(u, d1);

    int dis = 0;
    for(int x : a) {
        dis = max(dis, d1[x]);
    }
    cout << (dis + 1) / 2 << "\n";


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
