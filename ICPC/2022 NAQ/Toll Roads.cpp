#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 1;
vector<int> p, s, edge_size, level;
vector<pair<int, pii>> edges, tree_edges;
vector<vector<pii> > G;
vector<vector<int> > table, par;
int n, m, q;

void setup() {
    cin >> n >> m >> q;
    edges.resize(m);
    p.resize(n + 1);
    s.resize(n + 1, 1);
    edge_size.resize(n + 1, 0);
    level.resize(n + 1, 0);
    G.resize(n + 1);
    table.resize(20, vector<int> (n + 1, 0));
    par = table;
    for(int i = 0; i < m; i++) {
        cin >> edges[i].ss.ff >> edges[i].ss.ss >> edges[i].ff;
    }
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int find(int a) {
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int ind) {
    int cost = edges[ind].ff;
    auto [a, b] = edges[ind].ss;
    int pa = find(a), pb = find(b);
    if(pa == pb) return false;
    
    if(s[pa] > s[pb]) {
        swap(pa, pb);
    }
    // pb is bigger.
    s[pb] += s[pa];
    s[pa] = 0;
    p[pa] = pb;
    return true;
}

int getsize(int x) {
    int px = find(x);
    return s[px];
}

void dfs (int cur, int prev) {
    for(pii x : G[cur]) {
        if(x.ss != prev) {
            table[0][x.ss] = x.ff;
            par[0][x.ss] = cur;
            level[x.ss] = level[cur] + 1;
            dfs(x.ss, cur);
        }
    }
}

int max_edge(int i, int j) {
    if(tree_edges[i].ff > tree_edges[j].ff) {
        return i;
    }
    return j;
}

void build_sparse_table() {
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
            table[i][j] = max_edge(table[i - 1][j], table[i - 1][par[i - 1][j]]);
        }
    }
}

void build_spanning_tree() {
    // root = 1
    for(int i = 0; i < tree_edges.size(); i++) {
        auto edge = tree_edges[i];
        int cost = edge.ff;
        auto [a, b] = edge.ss;
        G[a].push_back({i, b});
        G[b].push_back({i, a});
    }
    dfs(1, 1);
    build_sparse_table();
}

int find_max_edge_to_lca(int a, int b) {
    if(level[a] > level[b]) {
        swap(a, b);
    }
    // a is higher.
    int la = level[a], lb = level[b], dif = lb - la, ans = table[0][b];

    for(int i = 0; i < 20; i++) {
        if(dif & (1 << i)) {
            ans = max_edge(table[i][b], ans);
            b = par[i][b];
        }
    }
    if(a == b) {
        return ans;
    }

    for(int i = 19; i >= 0; i--) {
        if(par[i][a] != par[i][b]) {
            ans = max_edge(ans, max_edge(table[i][a], table[i][b]));
            a = par[i][a];
            b = par[i][b];
        }
    }
    ans = max_edge(ans, table[0][a]);
    ans = max_edge(ans, table[0][b]);
    return ans;
}

pii query(int a, int b) {
    int ind = find_max_edge_to_lca(a, b);
    return {tree_edges[ind].ff, edge_size[ind]};
}

int main() {
    setup();
    sort(edges.begin(), edges.end());
    for(int i = 0; i < m; i++) {
        int j = i, cursize = tree_edges.size();

        while(j < m && edges[j].ff == edges[i].ff) {
            if(merge(j)) {
                tree_edges.push_back(edges[j]);
            }
            j++;
        }

        for(int k = cursize; k < tree_edges.size(); k++) {
            edge_size[k] = getsize(tree_edges[k].ss.ss);
        }
        i = j - 1;
    }

    build_spanning_tree();

    while(q--) {
        int a, b;
        cin >> a >> b;
        pii ans = query(a, b);
        cout << ans.ff << ' ' << ans.ss << '\n';
    }


    return 0;
}
