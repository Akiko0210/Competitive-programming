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

struct DSU {
    vector<int> p, size;
    DSU(int n) {
        p.resize(n + 1);
        size.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b) {
        int ap = find(a), bp = find(b);
        if(ap == bp) return false;

        if(ap > bp) {
            swap(ap, bp);
        }

        size[ap] += size[bp];
        size[bp] = 0;
        p[bp] = ap;
        return true;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> edges(m);
    map<pii, int> edgeInd;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        edgeInd[{a, b}] = i;
        edges[i] = {a, b};
    }

    vector<int> edge_val(m, k);

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        edge_val[edgeInd[{a, b}]] = i;
    }

    vector<int> inds(m);
    iota(inds.begin(), inds.end(), 0);

    sort(inds.begin(), inds.end(), [&](int a, int b) {
        return edge_val[a] > edge_val[b];
    });

    int components = n;
    DSU dsu(n);
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        auto [a, b] = edges[inds[i]];
        a--, b--;
        if(edge_val[inds[i]] != k) {
            ans.pb(components);
        }
        if(dsu.merge(a, b)) {
            components--;
        }
    }

    for(int i = k - 1; i >= 0; i--) {
        cout << ans[i] << " ";
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

