#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
// #define pb push_back
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
    int n, parts;
    vector<int> p, s;
    DSU(int n) {
        this->n = n;
        parts = n;
        p.resize(n);
        s.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) {
            return false;
        }
        if(s[pa] > s[pb]) {
            swap(pa, pb);
        }
        parts--;

        p[pa] = pb;
        s[pb] += s[pa];
        s[pa] = 0;
        return true;
    }

    bool isConnected() {
        return parts == 1;
    }
};

const int N = 5;

void solve() {
    int n;
    cin >> n;
    vector<bitset<N> > a(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        a[i] = bitset<N>(s);
        // debug(a[i]);
    }
    vector<int> inds(n);
    iota(inds.begin(), inds.end(), 0);
    sort(inds.begin(), inds.end(), [&](int i, int j) {
        return a[i].count() < a[j].count();
    });

    DSU dsu(n);

    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        int ind1 = inds[i];
        bitset<N> cur = a[ind1];
        for(int j = i - 1; j >= 0; j--) {
            int ind2 = inds[j];
            // debug(cur, a[ind2]);
            if((cur & a[ind2]) == a[ind2]) {
                // from ind1 to ind2;
                // debug(ind1, ind2, cur, a[ind2]);
                if(dsu.merge(ind1, ind2)) {
                    ans.push_back({ind1, ind2});
                } else {
                    // cout << "can't merge\n";
                    cout << "NO\n";
                    return;
                }
                cur ^= a[ind2];
            }
        }
        if(cur.count() != 1 || !cur[ind1]) {
            // cout << "bad result\n";
            // debug(ind1, cur);
            cout << "NO\n";
            return;
        }
    }

    if(!dsu.isConnected()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i < n; i++) {
        cout << ans[i - 1].ff + 1 << " " << ans[i - 1].ss + 1 << "\n";
    }
}

int main() {
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

