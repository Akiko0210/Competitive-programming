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
    int n, m, N;
    vector<int> p, s, mxx, mxy, mnx, mny;
    DSU(int n, int m) {
        this->n = n;
        this->m = m;
        N = n * m;
        p.resize(N);
        iota(p.begin(), p.end(), 0);
        s.resize(N, 1);
        mxx.resize(N, 0);
        mnx.resize(N, n - 1);
        mxy.resize(N, 0);
        mny.resize(N, m - 1);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    int ind(int x, int y) {
        return x * m + y;
    }

    void merge(int ax, int ay, int bx, int by) {
        int a = ind(ax, ay), b = ind(bx, by);
        merge(a, b);
        int p = find(a);
        mxx[p] = max(mxx[p], max(ax, bx));
        mnx[p] = min(mnx[p], min(ax, bx));
        mxy[p] = max(mxy[p], max(ay, by));
        mny[p] = min(mny[p], min(ay, by));
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);

        if(pa == pb) {
            return;
        }

        if(s[pa] > s[pb]) {
            swap(pa, pb);
        }

        p[pa] = pb;
        s[pb] += pa;
        s[pa] = 0;
    }

    bool connects(int x, int y) {
        int p = find(ind(x, y));
        // debug(mnx[p], mxx[p], mny[p], mxy[p]);
        // debug(p);
        bool top = (mnx[p] == 0 || mxy[p] == m - 1);
        bool bot = (mny[p] == 0 || mxx[p] == n - 1);
        return (top & bot);
    }

};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int> (m));
    vector<vector<pii> > pos(1e6 + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            // debug(mat[i][j]);
            if(mat[i][j] <= 1e6) {
                pos[mat[i][j]].push_back({i, j});
            }
        }
    }

    DSU dsu(n, m);

    auto merge_surround = [&] (int x, int y) {
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nx = x + i, ny = y + j;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    mat[nx][ny] == mat[x][y]) {
                    // debug(x, y, nx, ny);
                    dsu.merge(x, y, nx, ny);
                }
            }
        }
    };

    for(int i = 0; i <= 1e6; i++) {
        bool connect = false;
        for(auto el : pos[i]) {
            int x = el.ff, y = el.ss;
            merge_surround(x, y);
            // if(x > 0 && mat[x][y] >= mat[x - 1][y]) {
            //     dsu.merge(x, y, x - 1, y);
            // }
            // if(y > 0 && mat[x][y] >= mat[x][y - 1]) {
            //     dsu.merge(x, y, x, y - 1);
            // }
            if(dsu.connects(x, y)) {
                connect = true;
                break;
            }
            // debug(x, y);
        }
        // debug(connect);
        if(!connect) {
            cout << i << "\n";
            return;
        }
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

