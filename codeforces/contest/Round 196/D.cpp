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

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    if(n % 2 == 0) {
        cout << n + 1 << "\n";
        return;
    }

    auto dfs = [&](auto && self, int root, int cur, int prev, int curColor, vector<int>& colors) -> void {
        colors[cur] = curColor;
        for(int x : G[cur]) {
            if(x != prev) {
                if(cur == root)
                    curColor++;
                self(self, root, x, cur, curColor, colors);
            }
        }
    };

    auto check = [&](int root, int k) {
        vector<int> colors(n + 1, 0);
        dfs(dfs, root, root, root, 0, colors);
        
        // debug(k);
        // for(int i = 1; i <= n; i++) {
        //     cout << colors[i] << " ";
        // }
        // cout << "\n";
        for(int i = 1; i <= n; i++) {
            if(k - i <= n && k - i > 0 && k - i != i) {
                if(colors[i] != colors[k - i]) {
                    // debug(i, k - i);
                    return true;
                }
            }
        }
        return false;
    };

    vector<int> cands = {1, (n + 1) / 2, n};
    for(int i = 0; i < 3; i++) {
        if(check(cands[i], n + 2 - i)) {
            cout << n + 2 - i << "\n";
            return;
        }
    }

    cout << n << "\n";
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

