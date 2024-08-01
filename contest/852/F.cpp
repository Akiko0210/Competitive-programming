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
const int N = 3e5;

int a[N], b[N + 1], LEFT[N * 4], RIGHT[N * 4], v[N * 4];

void build (int i, int L, int R) {
    if(L == R) { 
        if(b[L]) {
            LEFT[i] = L;
            RIGHT[i] = R;
        } else {
            LEFT[i] = -1;
            RIGHT[i] = -1;
        }
        v[i] = INF;
        return;
    }

    int M = (L + R) / 2, x = i * 2, y = i * 2 + 1;
    build(x, L, M);
    build(y, M + 1, R);
    if(LEFT[x] == -1) {
        LEFT[i] = LEFT[y];
        RIGHT[i] = RIGHT[y];
        v[i] = v[y];
        return;
    } 

    if(LEFT[y] == -1) {
        LEFT[i] = LEFT[x];
        RIGHT[i] = RIGHT[x];
        v[i] = v[x];
        return;
    } 

    LEFT[i] = LEFT[x];
    RIGHT[i] = RIGHT[y];
    v[i] = min(min(v[x], v[y]), LEFT[y] - RIGHT[x]);
    debug(i, LEFT[i], RIGHT[i], v[i], v[x], v[y], LEFT[y], RIGHT[x]);
}

pair<pii, int> query(int i, int L, int R, int l, int r) {
    if(L > r || R < l) {
        return {{-1, -1}, 0};
    }
    if(L >= l && r >= R) {
        return {{LEFT[i], RIGHT[i]}, v[i]};
    }
    int M = (L + R) / 2, x = i * 2, y = i * 2 + 1;
    pair<pii, int> left = query(x, L, M, l, r);
    pair<pii, int> right = query(y, M + 1, R, l, r);
    if(left.ff.ff == -1)
        return right;
    
    if(right.ff.ff == -1) {
        return left;
    }

    return {{left.ff.ff, right.ff.ss}, min(min(left.ss, right.ss), right.ff.ff - left.ff.ss)};
}

int main() {
    // FAST
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }

    build(1, 1, n);

    while(q--) {
        int l, r;
        cin >> l >> r;
        auto ans = query(1, 1, n, l, r);
        cout << ans.ss << "\n";
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
