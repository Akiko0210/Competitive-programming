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

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<vector<array<int, 2> > > dis(n, vector<array<int, 2> > (n, {INF, INF}));

    for(int i = 0; i < n; i++) {
        queue<pii> q;
        q.push({i, 0});
        dis[i][i][0] = 0;

        while(!q.empty()) {
            auto [cur, d] = q.front();
            q.pop();

            for(int x : G[cur]) {
                int nd = d + 1;
                if(dis[i][x][nd % 2] == INF) {
                    dis[i][x][nd % 2] = nd;
                    // dis[x][i][nd % 2] = nd;
                    q.push({x, nd});
                }
            }
        }
    }

    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if(dis[a][b][c % 2] <= c) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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

