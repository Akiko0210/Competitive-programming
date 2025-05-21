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

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<pii> > g(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> ap;
    ap.push({{1, -1}, 1});
    vector<int> fa(n + 1, -1);
    while(!ap.empty()) {
        auto cur = ap.top();
        ap.pop();
        int cost = cur.ff.ff, edge = cur.ff.ss, node = cur.ss;
        if(fa[node] != -1) {
            continue;
        }
        fa[node] = cost;

        for(auto el : g[node]) {
            if(el.ss < edge) {
                ap.push({{cost + 1, el.ss}, el.ff});
            } else {
                ap.push({{cost, el.ss}, el.ff});
            }
        }
    }
    cout << *max_element(fa.begin(), fa.end()) << "\n";
    
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
