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

bool dfs(int cur, int prev, vector<vector<int> >& G, vector<int>& colors) {
    for(int x : G[cur]) {
        if(x == prev) continue;

        if(colors[x] == -1) {
            colors[x] = 1 - colors[cur];
            bool can = dfs(x, cur, G, colors);
            if(!can) return false;
        } else if(colors[x] == colors[cur]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<int> color(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            if(!dfs(i, i, G, color)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " ";
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

