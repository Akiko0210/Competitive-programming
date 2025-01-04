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
const int N = 2e5;
vector<vector<int> > best(N + 1);

int dfs(int cur, int prev, vector<vector<pii> >& G) {
    int sum = 0;
    // debug(cur, prev);
    for(pii x : G[cur]) {
        if(x.ff != prev) {
            sum += dfs(x.ff, cur, G) + x.ss;
        }
    }
    return sum;
}

void dfs1(int cur, int prev, vector<vector<pii> >& G, int sum) {
    best[sum].pb(cur);
    for(pii x : G[cur]) {
        if(x.ff != prev) {
            dfs1(x.ff, cur, G, sum + (x.ss == 1 ? -1 : 1));
        }
    }
}

int main() {
    FAST
    int n;
    cin >> n;
    vector<vector<pii> > G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb({v, 0}); // in-direction
        G[v].pb({u, 1}); // reverse-direction
    }

    int sum = dfs(1, 0, G);
    // debug(sum);
    dfs1(1, 0, G, sum);
    for(int i = 0; i < n; i++) {
        if(!best[i].empty()) {
            cout << i << "\n";
            sort(best[i].begin(), best[i].end());
            for(int x : best[i]) {
                cout << x << " ";
            }
            cout << "\n";
            return 0;
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

