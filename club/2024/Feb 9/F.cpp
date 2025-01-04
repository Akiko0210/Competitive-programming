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

const ll MOD = 1e9 + 7;
int a[200000], mx[800000], mn[800000];

void build(int i, int L, int R) {
    if(L == R) {
        mx[i] = L;
        mn[i] = L;
        return;
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    build(x, L, M);
    build(y, M + 1, R);
    
    mx[i] = (a[mx[x]] > a[mx[y]] ? mx[x] : mx[y]);
    mn[i] = (a[mn[x]] < a[mn[y]] ? mn[x] : mn[y]);
}

pii query(int i, int L, int R, int l, int r) {
    if(L >= l && r >= R) {
        return {mn[i], mx[i]};
    }
    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    pii lval = {-1, -1}, rval = {-1, -1};
    bool lprop = false, rprop = false;
    if(l <= M) {
        lprop = true;
        lval = query(x, L, M, l, r);
    }

    if(r > M) {
        rprop = true;
        rval = query(y, M + 1, R, l, r);
    }

    if(!lprop) {
        return rval;
    }
    if(!rprop) {
        return lval;
    }

    int mymin = (a[lval.ff] < a[rval.ff] ? lval.ff : rval.ff);
    int mymax = (a[lval.ss] > a[rval.ss] ? lval.ss : rval.ss);
    return {mymin, mymax};
}

void solve() {
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        pii res = query(0, 0, n - 1, l - 1, r - 1);
        if(a[res.ff] == a[res.ss]) {
            cout << "-1 -1\n";
            continue;
        }
        // cout << a[res.ff] << " " << a[res.ss] << " are nums\n";
        cout << res.ff + 1 << " " << res.ss + 1 << "\n";
    }
    cout << "\n";
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

