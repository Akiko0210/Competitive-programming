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
const int N = 2 * 1e5;
int n, m, q;

vector<int> mn(N * 4), mx(N * 4), a(N + 1), b(N + 1), fa(N + 1);
vector<bool> isok(N * 4);

void build(int i, int L, int R) {
    if(L == R) {
        mn[i] = mx[i] = fa[a[L]];
        isok[i] = true;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    build(x, L, M);
    build(y, M + 1, R);
    
    isok[i] = isok[x] & isok[y] & (mx[x] <= mn[y]);
    mn[i] = min(mn[x], mn[y]);
    mx[i] = max(mx[x], mx[y]);
    debug(i, L, R, isok[i], mn[i], mx[i]);
}

void update(int i, int L, int R, int ind, int newfa) {
    if(L == R) {
        fa[a[ind]] = newfa;
        mn[i] = mx[i] = fa[a[L]];
        isok[i] = true;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(M >= ind) update(x, L, M, ind, newfa);
    else update(y, M + 1, R, ind, newfa);

    isok[i] = isok[x] & isok[y] & (mx[x] <= mn[y]);
    mn[i] = min(mn[x], mn[y]);
    mx[i] = max(mx[x], mx[y]);
}

void solve() {
    cin >> n >> m >> q;


    vector<int> ind(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    for(int i = 0; i < m; i++) cin >> b[i];


    vector<set<int> > pos(n + 1);
    for(int i = 0; i < m; i++) {
        pos[b[i]].insert(i);
    }

    for(int i = 0; i <= n; i++) {
        if(!pos[i].empty()) {
            fa[i] = *pos[i].begin();
        } else {
            fa[i] = INF;
        }
    }

    build(0, 0, n - 1);

    if(isok[0]) {
        cout << "Ya\n";
    } else {
        cout << "Tidak\n";
    }

    while(q--) {
        int s, t;
        cin >> s >> t;
        // s iig t d ugnu.
        s--;
        int prev = b[s];
        pos[prev].erase(s);
        pos[t].insert(s);
        b[s] = t;
        if(pos[prev].empty()) {
            update(0, 0, n - 1, ind[prev], INF);
        } else {
            update(0, 0, n - 1, ind[prev], *pos[prev].begin());
        }

        if(pos[t].empty()) {
            update(0, 0, n - 1, ind[t], INF);
        } else {
            update(0, 0, n - 1, ind[t], *pos[t].begin());
        }

        // debug(mx[0], mn[0], 0, isok[0]);
        if(isok[0]) {
            cout << "Ya\n";
        } else {
            cout << "Tidak\n";
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

