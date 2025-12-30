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

const ll MOD = 998244353;

vector<ll> f(100, 0);

ll fac(int x) {
    if(f[x] > 0) return f[x];

    if(x == 0) return 1LL;
    return f[x] = fac(x - 1) * x % MOD;
}
ll pw(ll a, ll b) {
    if(b == 1) return a;
    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }
    return h;
}

void solve() {
    ll n, mx = 0, sum = 0, cnt_mx = 0;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if(i > 0) {
            if(a[i] == mx) cnt_mx++;
            else if(a[i] > mx) {
                mx = a[i];
                cnt_mx = 1;
            }
        }
    }
    ll val = n * (mx - 1) - sum, pos_i = max(min(n, max(-val, 0LL)) - cnt_mx + 1, 0LL), ans = 0;
    for(int i = cnt_mx; i < pos_i + cnt_mx; i++) {
        ans += fac(i - 1) * pw(fac(i - cnt_mx), MOD - 2) % MOD;
    }
    // debug(ans);
    ans = ans * cnt_mx % MOD * fac(n - cnt_mx) % MOD;
    cout << ans << "\n";
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

