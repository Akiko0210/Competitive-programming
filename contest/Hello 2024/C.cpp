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

int stree[1000000], a[200000];

int query(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return stree[i];
    }

    int M = (L + R) / 2, lval = -1, rval = -1;

    if(l <= M) {
        lval = query(i * 2 + 1, L, M, l, r);
    }
    if(r > M) {
        rval = query(i * 2 + 2, M + 1, R, l, r);
    }

    if(lval == -1) return rval;
    if(rval == -1) return lval;

    if(a[lval] >= a[rval]) return lval;
    return rval;
}

void update(int i, int L, int R, int ind, int val) {
    if(L == R) {
        a[ind] = val;
        stree[i] = ind;
        return;
    }
    int M = (L + R) / 2;
    if(M >= ind) {
        update(i * 2 + 1, L, M, ind, val); 
    } else {
        update(i * 2 + 2, M + 1, R, ind, val);
    }

    if(a[stree[i * 2 + 1]] >= a[stree[i * 2 + 2]]) {
        stree[i] = stree[i * 2 + 1];
    } else {
        stree[i] = stree[i * 2 + 2];
    }
}

void build(int i, int L, int R) {
    if(L == R) {
        stree[i] = L;
        return;
    }
    int M = (L + R) / 2;
    build(i * 2 + 1, L, M);
    build(i * 2 + 2, M + 1, R);
    if(a[stree[i * 2 + 1]] >= a[stree[i * 2 + 2]]) {
        a[stree[i]] = i * 2 + 1;
    } else {
        a[stree[i]] = i * 2 + 2;
    }
}

void solve() {
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

