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

vector<int> cnt, color;
vector<vector<int> > G;
int ans;

void dfs(int cur, int prev, int level) {
    cnt[level]++;
    int size = 1;
    for(int x : G[cur]) {
        if(x != prev) {
            dfs(x, cur, level + 1);
            size++;
        }
    }
    ans = max(ans, size);
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    cnt.clear();
    G.clear();
    color.clear();
    cnt.resize(n, 0);
    G.resize(n + 1);
    color.resize(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, 0, 0);
    for(int x : cnt) {
        ans = max(ans, x);
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

