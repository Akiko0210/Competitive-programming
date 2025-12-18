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
const int N = 1e5 + 1;
vector<bool> vis(N, 0), inloop(N, 0), vis1(N, 0);
vector<int> p(N), memo(N, 0);
vector<vector<int> > rp(N);

void dfs(int cur) {
    if(vis[cur]) {
        inloop[cur] = 1;
        // debug(cur);
        return;
    }
    vis[cur] = 1;

    if(vis1[cur]) {
        vis[cur] = 0;
        return;
    }
    vis1[cur] = 1;
    dfs(p[cur]);
    vis[cur] = 0;
}

void dfs1(int cur, vector<int>& nodes) {
    if(vis[cur]) {
        return;
    }
    nodes.push_back(cur);
    vis[cur] = 1;
    inloop[cur] = 1;
    dfs1(p[cur], nodes);
}

ll calc(int cur) {
    ll ans = 1;
    for(int x : rp[cur]) {
        ans = ans * calc(x) % MOD;
    }
    return (ans + 1) % MOD;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        rp[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        dfs(i);
    }
    ll res = 1;
    for(int i = 1; i <= n; i++) {
        if(inloop[i] && !vis[i]) {
            // debug(i);
            vector<int> nodes;
            dfs1(i, nodes);
            vector<int> children;
            for(int x : nodes) {
                for(int v : rp[x]) {
                    if(!inloop[v]) {
                        children.push_back(v);
                    }
                }
            }
            ll ans = 1;
            for(int x : children) {
                ans = ans * calc(x) % MOD;
            }
            res = res * (ans + 1) % MOD;
        }
    }

    cout << (res + MOD - 1) % MOD << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

