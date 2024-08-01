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
const int N = 2e5;


int dp[N + 1][20];
int p[N + 1];
int d[N + 1];
int n;
vector<vector<int> > G(N + 1);

void dfs(int cur, int prev) {
    p[cur] = prev;
    dp[cur][0] = prev;
    d[cur] = d[prev] + 1;
    for(int x : G[cur]) {
        if(x != prev) {
            dfs(x, cur);
        }
    }
}

void build() {
    for(int i = 1; i < 20; i++) {
        for(int j = 0; j < n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
}

int check(int a, int b) {
    int dif = d[a] - d[b];
    for(int i = 19; i >= 0; i--) {
        if((1 << i) & dif) {
            a = dp[a][i];
        }
    }

    if(a == b) {
        return 2;
    }

    return dp[a][0] == dp[b][0];
}

int main() {
    int m;
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[v].pb(u);
        G[u].pb(v);
    }

    dfs(1, 1);
    build();

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < 20; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(m--) {
        int k;
        cin >> k;
        vector<int> v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end(), [&](int x, int y) {
            return d[x] > d[y];
        });

        int cur = v[0];
        bool is_ans = true;
        for(int i = 1; i < k; i++) {
            if(d[cur] < d[v[i]]) {
                swap(cur, v[i]);
            }
            
            int status = check(cur, v[i]);
            debug(cur, v[i], status);
            if(status == 0) {
                is_ans = false;
                break;
            }

            if(status == 1) {
                cur = dp[v[i]][0];
            } else {
                cur = v[i];
            }
        }

        cout << (is_ans ? "YES\n": "NO\n");
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

