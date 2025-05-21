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

ll s[200001], a[200001], n;
ll ansS[200001], ans[200001];

void dfs1(int cur, int prev, vector<vector<int> >& edges) {
    s[cur] = 1;
    ans[cur] = 0;
    for(int x : edges[cur]) {
        if(x != prev) {
            dfs1(x, cur, edges);
            s[cur] += s[x];
            ans[cur] += ans[x] + (a[cur] ^ a[x]) * s[x];
        }
    }
}

void calcall(int cur, int prev, vector<vector<int> >& edges) {
    if(prev != -1)
        ansS[cur] = ansS[prev] + (n - 2 * s[cur]) * (a[prev] ^ a[cur]);

    for(int x : edges[cur]) {
        if(x != prev) {
            calcall(x, cur, edges);
        }
    }
}



void solve() {
    cin >> n;

    vector<vector<int> > edges(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs1(0, 0, edges);
    ansS[0] = ans[0];


    calcall(0, -1, edges);
    
    for(int i = 0; i < n; i++) {
        cout << ansS[i] << " ";
    }
    cout << "\n";

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
