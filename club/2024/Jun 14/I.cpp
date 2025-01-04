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
const int N = 4e5;

vector<int> stree(N * 4);
// vector<int> vis(N, 0);

void update(int i, int L, int R, int ind) {
    if(L == R) {
        // vis[ind] = 1;
        stree[i] = 1;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind <= M) {
        update(x, L, M, ind);
    } else {
        update(y, M + 1, R, ind);
    }

    stree[i] = stree[x] + stree[y];
}

int sum(int i, int L, int R, int l, int r) {
    // debug(l, r);
    if(l <= L && R <= r) {
        return stree[i];
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    int lval = 0, rval = 0;
    if(l <= M) {
        lval = sum(x, L, M, l, r);
    } 
    if(r > M) {
        rval = sum(y, M + 1, R, l, r);
    }

    return lval + rval;
}



int main() {
    FAST
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        m[l[i]] = 0;
        m[r[i]] = 0;
    }
    // ending is the first, begining is the second.
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&] (int x, int y) {
        return r[x] < r[y];
    });

    int cur = 0;
    for(auto &[k, v] : m) {
        v = cur++;
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        debug(m[l[ind[i]]], m[r[ind[i]]]);
        ans[ind[i]] = sum(0, 0, 2 * n, m[l[ind[i]]], m[r[ind[i]]]);

        update(0, 0, 2 * n, m[l[ind[i]]]);
    }

    for(int x : ans) {
        cout << x << "\n";
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

