#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define tii tuple<int, int, int, int>
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

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    void merge(int a, int b) {
        int ap = find(a), bp = find(b);
        if(ap == bp) return;

        if(size[ap] > size[bp]) swap(ap, bp);

        p[ap] = bp;
        size[bp] += size[ap];
        size[ap] = 0;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<tii> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b, i};
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n + 1);

    vector<tii> layer;
    vector<bool> included(m, false);
    for(int i = 0; i < m; i++) {
        layer.pb(edges[i]);

        if(i == m - 1 || get<0>(edges[i]) < get<0>(edges[i + 1])) {
            // calc the layer
            vector<pii> merge;
            for(auto [c, a, b, i] : layer) {
                if(!dsu.same(a, b)) {
                    merge.pb({a, b});
                    included[i] = true;
                }
            }


            for(auto [a, b] : merge) {
                dsu.merge(a, b);
            }
            layer.clear();
        }
    }

    for(int i = 0; i < m; i++) {
        cout << (included[i] ? "YES\n" : "NO\n");
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

