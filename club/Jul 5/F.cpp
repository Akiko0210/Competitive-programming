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

int n, m;

int dfs(int x, int y, vector<vector<bool> >& vis, vector<vector<int> >& a) {
    if(vis[x][y] || a[x][y] == 0) {
        return 0;
    }
    vis[x][y] = 1;
    int ans = a[x][y];
    int xd[] = {-1, 0, 1, 0};
    int yd[] = {0, -1, 0, 1};
    for(int i = 0; i < 4; i++) {
        int nx = x + xd[i], ny = y + yd[i];
        if(nx < n && nx >= 0 && ny < m && ny >= 0) {
            ans += dfs(nx, ny, vis, a);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool> > vis(n, vector<bool> (m, 0));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dfs(i, j, vis, a));
        }
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

