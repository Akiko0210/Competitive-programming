// Let's do Kosaraju's SCC

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

void dfs(int cur, vector<bool>& vis, vector<int>& output, vector<vector<int> >& G) {
    if(vis[cur]) return;

    vis[cur] = true;
    for(int x : G[cur]) {
        dfs(x, vis, output, G);
    }

    output.pb(cur);
}

void dfs1(int cur, vector<bool>& vis, vector<vector<int> >& G, vector<ll>& sum) {
    ll mx = 0;
    for(int x : G[cur]) {
        if(!vis[x]) {
            vis[x] = true;
            dfs1(x, vis, G, sum);
        }
        mx = max(mx, sum[x]);
    }
    sum[cur] += mx;
}

int main() {
    FAST
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1), Gt(n + 1);
    vector<int> coins(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        Gt[b].pb(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> order;
    for(int i = 1; i <= n; i++) {
        dfs(i, vis, order, G);
    }

    reverse(order.begin(), order.end());
    vis = vector<bool> (n + 1, false);
    vector<ll> compid(n + 1), compsum;
    for(int x : order) {
        if(vis[x]) continue;

        vector<int> component;
        dfs(x, vis, component, Gt);
        ll sum = 0;
        for(int x : component) {
            // cout << x << " ";
            sum += coins[x];
            compid[x] = compsum.size();
        }
        // cout << "\n";
        compsum.pb(sum);
    }

    int K = compsum.size();
    vector<vector<int> > Gcomp(K);
    for(int i = 1; i <= n; i++) {
        for(int x : G[i]) {
            if(compid[i] != compid[x]) {
                // debug(i, x);
                Gcomp[compid[i]].pb(compid[x]);
            }
        }
    }

    // vector<bool> vis(K, false);
    vis = vector<bool> (K, false);
    for(int i = 0; i < K; i++) {
        if(vis[i]) continue;

        // debug(i);
        vis[i] = true;
        dfs1(i, vis, Gcomp, compsum);
    }

    cout << *max_element(compsum.begin(), compsum.end()) << "\n";




    return 0;
}