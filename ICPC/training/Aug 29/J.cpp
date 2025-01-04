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
int n, m, q, N = 2e5;
vector<int> a;


vector<vector<ll> > stree;

void build(int i, int L, int R) {
    if(L == R) {
        stree[i][a[L]] = 1;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    build(x, L, M);
    build(y, M + 1, R);
    for(int j = 0; j < m; j++) {
        stree[i][j] = (stree[x][j] + stree[y][j]) % MOD;
        for(int k = 0; k < m; k++) {
            (stree[i][j] += stree[x][k] * stree[y][(j - k + m) % m]) %= MOD;
        }
        // debug(i, L, R, j, stree[i][j]);
    }
}

vector<ll> query(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return stree[i];
    }
    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    vector<ll> left(m, 0), right(m, 0), res(m, 0);
    if(l <= M) {
        left = query(x, L, M, l, r);
    }
    if(r > M) {
        right = query(y, M + 1, R, l, r);
    }
    
    for(int j = 0; j < m; j++) {
        res[j] = (left[j] + right[j]) % MOD;
        for(int k = 0; k < m; k++) {
            (res[j] += left[k] * right[(j - k + m) % m]) %= MOD;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    stree.resize(n * 4, vector<ll> (m, 0));
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    build(0, 0, n - 1);

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        vector<ll> res = query(0, 0, n - 1, l, r);
        cout << (res[0] + 1) % MOD << "\n";
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

