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

vector<int> X_cof, nodes;
vector<ll> C;
vector<vector<pii> > G;
bool isfixed, possible;
ll X;

void dfs(int cur) {
    if(!possible) return;
    nodes.pb(cur);
    // cur has X_cof.
    for(auto& [v, w] : G[cur]) {
        // cur num = X_cof[cur] * X + C[cur]
        if(X_cof[v] == 0) {
            X_cof[v] = -X_cof[cur];
            C[v] = (ll)w - C[cur];
            dfs(v);
        } else {
            if(-X_cof[cur] == X_cof[v]) {
                if(C[v] != w - C[cur]) {
                    possible = false;
                    return;
                }
                continue;
            }
            if(X_cof[cur] == X_cof[v]) {
                ll x2 = (ll)w - C[cur] - C[v];
                if(x2 % 2 != 0) {
                    possible = false;
                    return;
                }
                if(isfixed && X != x2 / 2 * X_cof[v]) {
                    possible = false;
                    return;
                }
                isfixed = true;
                X = x2 / 2 * X_cof[v];
            }
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    X_cof.clear();
    X_cof.resize(n, 0);
    C.clear();
    C.resize(n, 0);
    G.clear();
    G.resize(n);

    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(X_cof[i] == 0) {
            X_cof[i] = 1;
            C[i] = 0;
            possible = true;
            isfixed = false;
            nodes.clear();
            dfs(i);

            if(!possible) {
                cout << "-1\n";
                return;
            }

            if(isfixed) {
                // cout << "fixed\n";
                for(int x : nodes) {
                    ll val = X * X_cof[x] + C[x];
                    ans += (l[x] <= val && val <= r[x]);
                }
            } else {
                // cout << "not fixed\n";
                // line sweep.
                map<ll, int> cnt;
                for(int x : nodes) {
                    ll lval = l[x] - C[x], rval = r[x] - C[x];
                    if(X_cof[x] == -1) {
                        // C - l >= X >= C - r
                        rval = C[x] - l[x];
                        lval = C[x] - r[x];
                    }
                    cnt[lval]++;
                    cnt[rval + 1]--;
                }
                int sum = 0, mx = 0;
                for(auto& [k, v] : cnt) {
                    sum += v;
                    mx = max(mx, sum);
                }
                ans += mx;
            }
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

