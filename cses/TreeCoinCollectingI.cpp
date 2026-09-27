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
    int n;
    vector<vector<int> > G;
    vector<vector<int> > nxt;
    vector<vector<int> > closestCoin;
    vector<int> level;
    vector<bool> coin;
    Tree(int n, vector<vector<int> >& G, vector<bool>& coin) {
        this->n = n;
        this->G = G;
        this->coin = coin;
        nxt.resize(20, vector<int> (n, 0));
        closestCoin.resize(20, vector<int> (n, 1e9));
        level.resize(n, 0);
        
        dfs(0, 0);
        /*
        bfs from coin positions
        */ 

        findClosestCoinPositions();

        for(int i = 1; i < 20; i++) {
            for(int j = 0; j < n; j++) {
                int mynxt = nxt[i - 1][j];
                nxt[i][j] = nxt[i - 1][mynxt];
                closestCoin[i][j] = min(closestCoin[i - 1][j], closestCoin[i - 1][mynxt]);
            }
        }
    }

    void findClosestCoinPositions() {
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(coin[i]) {
                q.push(i);
                closestCoin[0][i] = 0;
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int x : G[cur]) {
                if(closestCoin[0][x] == 1e9) {
                    closestCoin[0][x] = closestCoin[0][cur] + 1;
                    q.push(x);
                }
            }
        }
    }

    void dfs(int cur, int prev) {
        for(int x : G[cur]) {
            if(x != prev) {
                level[x] = level[cur] + 1;
                nxt[0][x] = cur;
                dfs(x, cur);
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

    int getMin(int node, int ancestor) {
        int mn = 1e9, dis = level[node] - level[ancestor] + 1;
        for(int i = 0; i < 20; i++) {
            if(dis & (1 << i)) {
                mn = min(mn, closestCoin[i][node]); // wtf
                node = nxt[i][node];
            }
        }
        return mn;
    }

    int query(int a, int b) {
        int lca = LCA(a, b);
        int dis = level[a] + level[b] - level[lca] * 2;
        int mn = min(getMin(a, lca), getMin(b, lca));
        return dis + mn * 2;
    }
};

int main() {
    FAST
    int n, q;
    cin >> n >> q;
    vector<vector<int> > G(n);
    vector<bool> coins(n);
    for(int i = 0; i < n; i++) {
        // cin >> coins[i];
        int x;
        cin >> x;
        coins[i] = x;
    }

    // bfs from coin positions.
    /*
        distance(a, b) + min coin distance on the path.
    */ 

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    Tree tree(n, G, coins);

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

