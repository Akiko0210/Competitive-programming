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

int n, m;
void dfs(int cur, vector<vector<int> >& G, vector<int>& mxCities) {
    if(cur == n) {
        mxCities[cur] = 1;
        return;
    }
    if(mxCities[cur] != -1) return;
    
    mxCities[cur] = 0;

    for(int x : G[cur]) {
        dfs(x, G, mxCities);
        if(mxCities[x] > 0) {
            mxCities[cur] = max(mxCities[cur], mxCities[x] + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    // 1 to n with as many cities as possible;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
    }

    vector<int> mxCitites(n + 1, -1);
    // there's no cycles
    dfs(1, G, mxCitites);
    if(mxCitites[1] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path = {1};
    while(path.back() != n) {
        int cur = path.back(), nxt = G[cur][0];
        for(int x : G[cur]) {
            if(mxCitites[nxt] < mxCitites[x]) {
                nxt = x;
            }
        }
        path.pb(nxt);
    }
    cout << path.size() << "\n";
    for(int x : path) {
        cout << x << " ";
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

