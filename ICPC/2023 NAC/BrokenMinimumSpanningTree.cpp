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

using Edge = tuple<int, int, int, int, int>;

struct DSU {
    int n;
    vector<int> p, s;
    DSU(int n) {
        this->n = n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        s.resize(n, 1);
    }

    int find (int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b) {
        int PA = find(a), PB = find(b);
        if(PA == PB) return false;

        if(s[PA] > s[PB]) swap(PA, PB);

        p[PA] = PB;
        s[PB] += s[PA];
        s[PA] = 0;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<Edge> curMst(n - 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {w, i, u, v, 0};
        if(i < n - 1) {
            curMst[i] = edges[i];
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    vector<Edge> add;
    for(auto &[w, i, u, v, _] : edges) {
        // debug(w, out, u, v);
        if(dsu.merge(u, v)) {
            // in MST
            if(i < n - 1) {
                get<4>(curMst[i]) = 1;
            } else {
                add.pb({w, i, u, v, 1});
                /*
                we need to bring it in.
                What's the corresponding edge that needs to be removed? 
                Just mark it as to be added? 
                */ 
            }
        }
    }

    int ind = 0;
    for(int i = 0; i < n - 1; i++) {
        if(get<4>(curMst[i]) == 1) { // in MST
            swap(curMst[ind++], curMst[i]);
        }
    }

    vector<pii> ans;

    for(Edge e : add) {
        // for every add edge, find the edge that we can remove and add.
        // create the graph. 
        DSU checker(n);
        // sort my currentMst.
        curMst.pb(e);
        swap(curMst[ind++], curMst[n - 1]);

        for(int i = 0; i < n; i++) {
            auto [w, ind, u, v, in] = curMst[i];
            if(!checker.merge(u, v)) {
                // remove this edge and it's guarenteed to be not in the real MST.
                // add this to the ans.
                ans.pb({ind, get<1>(e)});
                swap(curMst[n - 1], curMst[i]);
                curMst.pop_back();
                break;
            }
        }
    }
    // debug(add.size());
    cout << ans.size() << "\n";
    for(auto el : ans) {
        cout << el.ff + 1 << " " << el.ss + 1 << "\n";
    }



    return 0;
}
