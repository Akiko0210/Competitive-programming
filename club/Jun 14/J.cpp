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

void dfs(int cur, vector<int>& c, vector<int>& csum, vector<vector<int> >& G) {
    if(c[cur] >= 0) return;

    c[cur] = 0;
    csum[cur] = 0;

    for(int x : G[cur]) {
        dfs(x, c, csum, G);
        c[cur] += c[x] + 1;
        // debug(x, c[x], csum[x]);
        csum[cur] += c[x] + csum[x] + 1;
    }
    // debug(cur, c[cur], csum[cur]);
}

void dfs1(int cur, vector<vector<int> >& G, vector<int>& psum, vector<int>& ppsum) {
    if(ppsum[cur] >= 0) {
        return;
    }
    ppsum[cur] = 0;
    for(int x : G[cur]) {
        dfs1(x, G, psum, ppsum);
        ppsum[cur] += ppsum[x] + psum[x];
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > G(n + 1), G1(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G1[v].pb(u);
    }

    vector<int> p(n + 1, -1), c, psum, csum, ppsum, ccsum; 
    c = psum = csum = ppsum = ccsum = p;
    
    for(int i = 1; i <= n; i++) {
        if(G[i].size() == 0) {
            // cout << "parent penetration at " << i << "\n";
            dfs(i, p, psum, G1);
        }

        if(G1[i].size() == 0) {
            // cout << "child penetration at " << i << "\n";
            dfs(i, c, csum, G);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(G[i].size() == 0) {
            // cout << "parent penetration at " << i << "\n";
            dfs1(i, G1, csum, ccsum);
        }

        if(G1[i].size() == 0) {
            // cout << "child penetration at " << i << "\n";
            dfs1(i, G, psum, ppsum);
        }
    }

    // cout << "children: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << c[i] << " ";
    // }
    // cout << "\n";
    // cout << "childrensum: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << csum[i] << " ";
    // }
    // cout << "\n";
    // cout << "parent: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << p[i] << " ";
    // }
    // cout << "\n";
    // cout << "parentsum: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << psum[i] << " ";
    // }
    // cout << "\n";
    // cout << "p parentsum: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << ppsum[i] << " ";
    // }
    // cout << "\n";
    // cout << "c childrensum: ";
    // for(int i = 1; i <= n; i++) {
    //     cout << ccsum[i] << " ";
    // }
    // cout << "\n";

    /*
    p[a]
    c[a]
    psum[a]
    hsum[a]

    p -> psum[a] - c[a] * p[a] + hsum[a];
    */

    vector<vector<int> > ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int val = ppsum[i] - c[i] * p[i] - csum[i];
        // int val1 = ccsum[i] - p[i] * c[i] - psum[i];
        int val1 = p[i];
        // debug(val, val1);
        ans[val + val1].pb(i);
    }

    for(int i = 0; i <= n; i++) {
        if(ans[i].size() > 0) {
            cout << i << "\n";
            for(int x : ans[i]) {
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

