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

    ll key(int a, int b) {
        int ap = find(a), bp = find(b);
        if(ap == bp) return -1;
        if(ap > bp) swap(ap, bp);

        return ap * n + bp;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<tii> edges(m), original;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b, i};
    }
    original = edges;

    sort(edges.begin(), edges.end());
    vector<ll> key(m, -1);
    vector<tii> layer;
    DSU dsu(n + 1);

    for(int i = 0; i < m; i++) {
        layer.pb(edges[i]);
        if(i == m - 1 || get<0>(edges[i]) != get<0>(edges[i + 1])) {
            for(auto [c, a, b, ind] : layer) {
                // debug(a, b, c, ind);
                // debug(dsu.find(a), dsu.find(b));
                if(dsu.key(a, b) != -1) {
                    key[ind] = dsu.key(a, b);
                }
            }

            for(auto [c, a, b, ind] : layer) {
                dsu.merge(a, b);
            }

            layer.clear();
        }
    }

    // for(int x : key) {
    //     cout << x << " ";
    // }
    // cout << "\n";



    while(q--) {
        int qn;
        cin >> qn;
        vector<int> inds(qn);
        for(int i = 0; i < qn; i++) {
            cin >> inds[i];
            inds[i]--;
        }
        
        unordered_set<ll> s;
        bool can = true;
        map<int, int> comp;
        for(int x : inds) {
            comp[get<1>(original[x])] = 0;
            comp[get<2>(original[x])] = 0;

            if(key[x] == -1 || s.find(key[x]) != s.end()) {
                can = false;
                break;
            }
            s.insert(key[x]);
        }

        int cnt = 0;
        for(auto &[key, val] : comp) {
            val = cnt++;
        }
        DSU dsu(cnt);
        for(int x : inds) {
            auto [c, a, b, ind] = original[x];
            int ca = comp[a], cb = comp[b];
            if(dsu.find(ca) == dsu.find(cb)) {
                can = false;
                break;
            }

            dsu.merge(ca, cb);
        }

        cout << (can ? "YES\n" : "NO\n");
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

