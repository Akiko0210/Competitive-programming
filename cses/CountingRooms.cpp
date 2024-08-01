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

int main() {
    int n, m;
    cin >> n >> m ;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x[] = {0, 1, 0, -1};
    int y[] = {1, 0, -1, 0};
    int ans = 0;
    vector<vector<bool> > vis(n, vector<bool> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || a[i][j] == '#') continue;
            queue<pii> q;
            q.push({i, j});
            while(!q.empty()) {
                pii cur = q.front();
                q.pop();
                if(vis[cur.ff][cur.ss]) 
                    continue;
                vis[cur.ff][cur.ss] = 1;
                // debug(cur.ff, cur.ss);
                for(int i = 0; i < 4; i++) {
                    int nx = cur.ff + x[i], ny = cur.ss + y[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#')
                        continue;

                    q.push({nx, ny});
                }
            }
            // cout << "------\n";
            ans ++;
        }
    }
    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

