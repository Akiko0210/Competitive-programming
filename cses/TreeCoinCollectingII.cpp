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

struct Tree {
    int n, root;
    vector<vector<int> > G;
    vector<vector<int> > nxt;
    vector<int> level, coins, dis;
    vector<ll> collectAll;
    vector<bool> hasCoin;
    Tree(int n, vector<vector<int> >& G, vector<bool>& coin) {
        this->n = n;
        this->G = G;
        this->hasCoin = coin;
        for(int i = 0; i < n; i++) {
            if(hasCoin[i]) {
                root = i;
                break;
            }
        }
        nxt.resize(20, vector<int> (n, root));
        level.resize(n, 0);
        coins.resize(n, 0);
        collectAll.resize(n, 0);
        dis.resize(n, 0);
        // I suspect we're choosing a wrong root.
        dfs(root, root);

        for(int i = 1; i < 20; i++) {
            for(int j = 0; j < n; j++) {
                int mynxt = nxt[i - 1][j];
                nxt[i][j] = nxt[i - 1][mynxt];
            }
        }

        for(int i = 0; i < n; i++) {
            int cur = i;
            if(coins[i]) continue;

            for(int j = 19; j >= 0; j--) {
                if(coins[nxt[j][cur]] == 0) {
                    dis[i] += (1 << j);
                    cur = nxt[j][cur];
                }
            }
            dis[i]++;
        }
    }

    void dfs(int cur, int prev) {
        coins[cur] = hasCoin[cur];
        for(int x : G[cur]) {
            if(x != prev) {
                level[x] = level[cur] + 1;
                nxt[0][x] = cur;
                dfs(x, cur);
                if(coins[x] > 0) {
                    coins[cur] += coins[x];
                    collectAll[cur] += collectAll[x] + 2;
                }
            }
        }
    }

    int LCA(int a, int b) {
        if(level[a] < level[b]) {
            swap(a, b);
        }

        int dif = level[a] - level[b];
        for(int i = 0; i < 20; i++) {
            if((1 << i) & dif) {
                a = nxt[i][a];
            }
        }

        if(a == b) return a;

        for(int i = 19; i >= 0; i--) {
            if(nxt[i][a] != nxt[i][b]) {
                a = nxt[i][a];
                b = nxt[i][b];
            }
        }

        return nxt[0][a];
    }

    int distance(int a, int b) {
        int lca = LCA(a, b);
        return level[a] + level[b] - 2 * level[lca];
    }

    int jump(int a) {
        int d = dis[a];
        for(int i = 0; i < 20; i++) {
            if(d & (1 << i)) {
                a = nxt[i][a];
            }
        }
        return a;
    }

    int query(int a, int b) {
        // debug(a, b, lca);
        int ra = jump(a), rb = jump(b);

        ll ans = collectAll[root] + dis[a] + dis[b] - distance(ra, rb);
        return ans;
    }
};

int main() {
    FAST
    int n, q;
    cin >> n >> q;
    vector<vector<int> > G(n);
    vector<bool> coins(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        coins[i] = x;
    }

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    Tree tree(n, G, coins);

    // cout << tree.collectAll[0] << "\n";
    // for(int x : tree.collectAll) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    // for(int x : tree.dis) {
    //     cout << x << " ";
    // }
    // cout << "\n\n";

    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << tree.query(a, b) << "\n";
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

