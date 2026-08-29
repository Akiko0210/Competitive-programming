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
    int pieces, largest;
    DSU(int n) {
        pieces = n - 1;
        largest = 1;
        p.resize(n);
        size.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b) {
        int ap = find(a), bp = find(b);

        if(ap == bp) return false;

        pieces --;
        if(size[ap] > size[bp]) swap(ap, bp);

        // ap is always smaller in size
        size[bp] += size[ap];
        largest = max(largest, size[bp]);
        size[ap] = 0;
        p[ap] = bp;
        return true;
    }

    int getComponents() {
        return pieces;
    }

    int getLargest () {
        return largest;
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
        cout << dsu.getComponents() << " " << dsu.getLargest() << "\n";
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

