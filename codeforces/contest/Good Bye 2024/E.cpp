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

vector<bool> iscold, ishot;
vector<int> cold;

void dfs(int cur, int p, vector<vector<int> >& G) {
    cold[cur] = iscold[cur];
    for(int x : G[cur]) {
        if(x != p) {
            dfs(x, cur, G);
            cold[cur] += cold[x];
        }
    }
    // debug(cur, cold[cur], iscold[cur]);
}

ll dfs2(int cur, int p, vector<vector<int> >& G) {
    if(p != cur) {
        cold[p] -= cold[cur];
        cold[cur] += cold[p];
    }
    ll ans = 0;
    if(ishot[cur]) {
        for(int x : G[cur]) {
            if(iscold[x] || ishot[x]) {
                ans += cold[cur] - cold[x];
            }
        }
    }


    for(int x : G[cur]) {
        if(x != p) {
            ans += dfs2(x, cur, G);
        }
    }

    cold[cur] -= cold[p];
    cold[p] += cold[cur];

    return ans;
}

void solve() {
    /*
        Nora - p - 1st
        Aron - q - 2nd

        when p is already a leaf => Aron can't win
        when p is 1 step away from a leaf => Aron can't win. 
        when q is 1 or more step away from a leaf => Aron can't win. 
        => q has to be a leaf. 
    */

    ll n;
    cin >> n;
    iscold.resize(n, true);
    ishot.resize(n, false);
    cold.resize(n, 0);

    for(int i = 0; i < n; i++) {
        iscold[i] = true;
        ishot[i] = false;
        cold[i] = 0;
    }
    vector<vector<int> > G(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll leaf = 0, vsec = 0;
    for(int i = 0; i < n; i++) {
        if(G[i].size() == 1) {
            iscold[i] = false;
            leaf++;
            if(G[G[i][0]].size() > 1) {
                ishot[G[i][0]] = true;
                iscold[G[i][0]] = false;
            }
        }
    }


    ll ans = leaf * (n - leaf);
    dfs(0, 0, G);
    ans += dfs2(0, 0, G);

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

