#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define tii tuple<int, int, int>
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

struct DSU {
    int n;
    vector<int> p, size;
    DSU(int n) {
        this->n = n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b) {
        int ap = find(a), bp = find(b);
        if(ap == bp) {
            return false;
        }

        if(size[ap] > size[bp]) swap(ap, bp);

        p[ap] = bp;
        size[bp] += size[ap];
        size[ap] = 0;
        return true;
    }
};


struct Tree {
    int n;
    vector<vector<pii> > G;
    vector<vector<pii> > table;
    vector<int> level;
    Tree(int n, vector<tii>& edges) {
        this->n = n;
        table.resize(20, vector<pii> (n));
        level.resize(n, 0);
        G.resize(n);
        
        // debug("here");
        for(auto [a, b, c] : edges) {
            // debug(a, b, G.size());
            G[a].pb({b, c});
            G[b].pb({a, c});
        }
        

        table[0][1] = {0, 0};
        level[1] = 0;
        dfs(1, 1);
        

        for(int i = 1; i < 20; i++) {
            for(int j = 0; j < n; j++) {
                int nxt1 = table[i - 1][j].ff;
                int w1 = table[i - 1][j].ss;
                int nxt2 = table[i - 1][nxt1].ff;
                int w2 = table[i - 1][nxt1].ss;
                table[i][j] = {nxt2, max(w1, w2)};
            }
        }

        // for(int i = 0; i < 2; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << "{" << table[i][j].ff << "," << table[i][j].ss << "} ";
        //     }
        //     cout << "\n";
        // }
    }

    void dfs(int cur, int prev) {
        // debug(cur, prev);
        for(auto [x, w] : G[cur]) {
            if(x != prev) {
                level[x] = level[cur] + 1;
                table[0][x] = {cur, w};
                dfs(x, cur);
            }
        }
    }

    int maxEdgeToLCA(int a, int b) {
        if(level[a] < level[b]) {
            swap(a, b);
        }

        // debug(a, b);

        int dif = level[a] - level[b];
        int mx_edge = 0;
        for(int i = 0; i < 20; i++) {
            if((1 << i) & dif) {
                // debug(i, a, table[i][a].ss);
                mx_edge = max(mx_edge, table[i][a].ss);
                a = table[i][a].ff;
            }
        }

        if(a == b) return mx_edge;

        for(int i = 19; i >= 0; i--) {
            if(table[i][a].ff != table[i][b].ff) {
                mx_edge = max(mx_edge, table[i][a].ss);
                mx_edge = max(mx_edge, table[i][b].ss);
                
                a = table[i][a].ff;
                b = table[i][b].ff;
            }
        }

        mx_edge = max(table[0][a].ss, mx_edge);
        mx_edge = max(table[0][b].ss, mx_edge);
        return mx_edge;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<tii> edges(m), original;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    original = edges;
    sort(edges.begin(), edges.end());
    DSU dsu(n + 1);
    vector<tii> treeEdges;
    long long total_weight = 0;
    for(auto [c, a, b] : edges) {
        if(dsu.merge(a, b)) {
            treeEdges.pb({a, b, c});
            total_weight += c;
            // debug(a, b, c);
        }
    }

    // debug(total_weight);

    Tree tree(n + 1, treeEdges);
    for(auto [c, a, b] : original) {
        int mx = tree.maxEdgeToLCA(a, b);
        // debug(a, b, mx, c);
        cout << total_weight - mx + c << "\n";
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

