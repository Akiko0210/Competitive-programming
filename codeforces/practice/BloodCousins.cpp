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
const int N = 1e5;
vector<int> lvl(N + 1, 0), ind(N + 1), sizes(N + 1, 1);
vector<vector<int> > G(N + 1), layers(N + 1);
vector<vector<int> > dp(20, vector<int> (N + 1, 0));
int curind = 0;

void dfs(int cur) {
    ind[cur] = curind++;
    layers[lvl[cur]].pb(ind[cur]);
    for(int x : G[cur]) {
        dp[0][x] = cur;
        lvl[x] = lvl[cur] + 1;
        dfs(x);
        sizes[cur] += sizes[x];
    }
}

int jump(int v, int p) {
    for(int i = 0; i < 20; i++) {
        if(p & (1 << i)) {
            v = dp[i][v];
        }
    }
    return v;
}

int get_cousins(int v, int p) {
    if(lvl[v] <= p) 
        return 0;

    int par = jump(v, p);
    int len = upper_bound(layers[lvl[v]].begin(), layers[lvl[v]].end(), ind[par] + sizes[par]) - \
              lower_bound(layers[lvl[v]].begin(), layers[lvl[v]].end(), ind[par]);
    return len - 1;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        G[p].pb(i);
    }

    dfs(0);
    
    for(int j = 1; j < 20; j++) {
        for(int i = 0; i <= n; i++) {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int v, p;
        cin >> v >> p;
        cout << get_cousins(v, p) << " ";
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

