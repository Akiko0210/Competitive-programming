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


vector<vector<int> > G;
vector<ll> ans, score, sum, d, a;

void dfs(int cur, int prev) {
    sum[cur] = a[cur];
    int d1 = 0, d2 = 0;
    for(int x : G[cur]) {
        if(x != prev) {
            dfs(x, cur);
            if(d[x] + 1 >= d1) {
                d2 = d1;
                d1 = d[x] + 1;
            } else if (d[x] + 1 > d2) {
                d2 = d[x] + 1;
            }
            
            sum[cur] += sum[x];
            score[cur] += score[x] + sum[x];
            d[cur] = max(d[cur], d[x] + 1);
        }
    }

    ans[cur] = score[cur];

    for(int x : G[cur]) {
        if(x != prev) {
            // make op in child subtree.
            ans[cur] = max(ans[cur], score[cur] - score[x] + ans[x]);
            // make op here.
            ll cost;
            if(d[x] + 1 == d1) {
                // plug from d2
                cost = score[cur] + sum[x] * d2;
            } else {
                cost = score[cur] + sum[x] * d1;
            }
            // debug(cost, x);
            ans[cur] = max(ans[cur], cost);
        }
    }
    // debug(cur, score[cur], ans[cur]);
}

void solve() {
    G.clear();
    ans.clear();
    score.clear();
    sum.clear();
    d.clear();
    a.clear();

    int n;
    cin >> n;
    G.resize(n);
    ans.resize(n);
    score.resize(n);
    sum.resize(n);
    d.resize(n);
    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';



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

