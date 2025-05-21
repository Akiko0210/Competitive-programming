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
    vector<int> p;
    vector<int> s;
    DSU(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        s.resize(n + 1, 1);
    }
    int find(int x) {
        if(p[x] == x) 
            return p[x];
        return p[x] = find(p[x]);
    }

    bool Union (int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(s[pu] < s[pv]) 
            swap(pu, pv);
        
        p[pv] = pu;
        s[pu] += s[pv];
        s[pv] = 0;
        return true;
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

/*
    G:
    [1, 2, [3], 4]

    F:
    [1, [2], 3, 4]

*/





void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU F(n + 1), G(n + 1);

    vector<pii> e1(m1), e2(m2);
    for(int i = 0; i < m1; i++) {
        cin >> e1[i].ff >> e1[i].ss;
    }
    for(int i = 0; i < m2; i++) {
        cin >> e2[i].ff >> e2[i].ss;
        G.Union(e2[i].ff, e2[i].ss);
    }


    int ans = 0;

    for(int i = 0; i < m1; i++) {
        if(!G.isConnected(e1[i].ff, e1[i].ss)) {
            // this edge must be deleted. 
            
            ans++;
        } else {
            // this edge can remain. 
            F.Union(e1[i].ff, e1[i].ss);
        }
    }

    for(int i = 1; i <= n; i++) {
        int gParent = G.find(i);
        if(!F.isConnected(gParent, i)) {
            // in the same set.
            F.Union(i, gParent);
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    FAST
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
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

