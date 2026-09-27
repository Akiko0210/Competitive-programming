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

    int cnt(int x) {
        return size[find(x)];
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
    int n;
    cin >> n;
    vector<tii> edges(n - 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[i] = {c, a, b};
    }
    DSU dsu(n);
    sort(edges.rbegin(), edges.rend());
    ll ans = 0;
    for(auto [c, a, b] : edges) {
        ll sa = dsu.cnt(a), sb = dsu.cnt(b);
        ans += sa * sb * c;
        dsu.merge(a, b);
    }

    cout << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

