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

void discover(int cur, int prev, vector<vector<int> >& G, vector<bool>& vis, vector<int>& comp) {
    vis[cur] = true;
    comp.push_back(cur);
    for(int x : G[cur]) {
        if(x != prev && !vis[x]) {
            discover(x, cur, G, vis, comp);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> hasStore(n + 1, false);
    vector<int> stores;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        stores.pb(x);
        hasStore[x] = 1;
    }

    vector<vector<int> > G(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    // get the components.
    vector<bool> vis(n + 1, false);
    vector<vector<int> > components;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vector<int> comp;
            discover(i, i, G, vis, comp);
            components.push_back(comp);
        }
    }

    // find the values for every other node by running bfs from the stores. 
    // keep the closest store index for them. 
    vector<int> val(n + 1, -1), source(n + 1, -1);
    queue<int> q;
    for(int x : stores) {
        val[x] = 0;
        source[x] = x;
        q.push(x);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int x : G[cur]) {
            if(val[x] == -1) {
                source[x] = source[cur];
                val[x] = val[cur] + 1;
                q.push(x);
            }
        }
    }

    // now calculate the values for the stores.
    vector<int> storevals(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        for(int j : G[i]) {
            int a = source[i], b = source[j], d = val[i] + val[j] + 1;
            if(a != -1 && b != -1 && a != b) {
                storevals[a] = (storevals[a] == -1 ? d : min(storevals[a], d));
                storevals[b] = (storevals[b] == -1 ? d : min(storevals[b], d));
            }
        }
    }

    for(int store : stores) {
        val[store] = storevals[store];
    }

    for(int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

