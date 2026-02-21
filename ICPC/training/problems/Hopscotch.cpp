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

ll pw(ll a, ll b) {
    if(b == 0) return 1;

    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }
    return h;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> fac(n + 1, 1), inv_fac(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ll ans = 0;
    for(int i = 1; i <= n && (x * i <= n && y * i <= n); i++) {
        int extra_x = n - x * i;
        int extra_y = n - y * i;

        // extra balls into i basket. i ^ extra / extra!
        // i = 2, e = 2
        // 2 0, 1 1, 0 2
        // i = 3, e = 3
        /*
            x1 + x2 + x3 + ... xi = extra
            choose i - 1 from i + extra - 1
        */
        ll inv = pw(fac[i - 1], MOD - 2);
        ll xval = fac[i + extra_x - 1] * inv % MOD * pw(fac[extra_x], MOD - 2) % MOD;
        ll yval = fac[i + extra_y - 1] * inv % MOD * pw(fac[extra_y], MOD - 2) % MOD;
        debug(i, xval * yval);
        (ans += xval * yval) %= MOD;
    }

    cout << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

