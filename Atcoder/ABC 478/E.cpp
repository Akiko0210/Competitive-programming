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

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > G0(n), G1(n), GU(n), GT(n);
    vector<int> indeg(n, 0);
    bool can = true;
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if(u == v) {
            if(t == 1) can = false;
            else continue;
        }
        if(t == 0)
            G0[u].pb(v);
        else 
            G1[u].pb(v);
        
        GU[u].pb(v);
        GT[v].pb(u);
    }

    if(!can) {
        cout << "No\n";
        return 0;
    }

    auto dfs = [](auto &&self, int cur, vector<bool>& vis, vector<vector<int> >& G, vector<int>& order) -> void {
        vis[cur] = true;
        for(int x : G[cur]) {
            if(!vis[x]) {
                self(self, x, vis, G, order);
            }
        }
        
        order.pb(cur);
    };
    vector<bool> vis(n, 0);
    vector<int> order;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            // debug(i);
            dfs(dfs, i, vis, GU, order);
        }
    }
    
    // reverse(order.begin(), order.end());
    vector<int> comp_id(n, 0);
    vis = vector<bool> (n, false);
    int compcnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        // debug(order[i]);
        if(!vis[order[i]]) {
            vector<int> curcomp;
            compcnt++;
            dfs(dfs, order[i], vis, GT, curcomp);
            for(int x : curcomp) {
                comp_id[x] = compcnt;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        // cout << comp_id[i] << " ";
        for(int x : G1[i]) {
            if(comp_id[x] <= comp_id[i]) {
                cout << "No\n";
                return 0;
            }
        }
    }
    // cout << "\n";

    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << comp_id[i] << " ";
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

