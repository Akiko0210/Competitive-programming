#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
#define M_PI          3.141592653589793238462643383279502884L

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
const int N = 1e5;
// const double pi = 3.14159265358979323846;

vector<ll> stree(N * 4);

void update(int i, int L, int R, int ind, ll val) {
    if(L == R) {
        stree[i] = val;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind <= M) {
        update(x, L, M, ind, val);
    } else {
        update(y, M + 1, R, ind, val);
    }

    stree[i] = max(stree[x], stree[y]);
}

ll query(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return stree[i];
    }
    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    ll lval = 0, rval = 0;
    if(l <= M) {
        lval = query(x, L, M, l, r);
    } 
    if(r > M) {
        rval = query(y, M + 1, R, l, r);
    }

    return max(lval, rval);
}


int main() {
    int n;
    cin >> n;
    vector<ll> vol(n);
    map<ll, int> m;
    // if j < i and vol[i] > vol[j]
    for(int i = 0; i < n; i++) {
        // volume
        ll r, h;
        cin >> r >> h;
        vol[i] = r * r * h;
        m[vol[i]] = 0;
        // just segment tree.
        // coordinate compression. 
    }

    int prev = 0;
    for(auto &[k, v] : m) {
        v = prev++;
    }

    for(int i = 0; i < n; i++) {
        int ind = m[vol[i]];
        ll maxval = query(0, 0, n - 1, 0, ind);
        update(0, 0, n - 1, ind, maxval + vol[i]);
    }

    double ans = M_PI * (double)stree[0];
    cout << fixed << setprecision(9) << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

