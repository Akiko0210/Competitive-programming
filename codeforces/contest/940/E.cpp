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
const int maxN = 1e6 + 5;
vector<ll> dp(maxN, 0), fac(maxN, 1);
// vector<ll> dp(1e6 + 1, 0);

/*
    dp[i] = ans[1] * C(i, 1) + ans[2] * C(i, 2) ... ans[i] * C(i, i);

    final:
    + ans[1] * (C(1, 1) + C(2, 1) + C(3, 1) + ... + C(n, 1))
    + ans[2] * (C(2, 2) + C(3, 2) + C(4, 2) + ... + C(n, 2))
    + ...
    + ans[n] * C(n, n)
*/

ll pw(ll a, ll b) {
    if(b == 1) return a;

    ll half = pw(a, b / 2);
    (half *= half) %= MOD;

    if(b & 1) {
        (half *= a) %= MOD;
    }

    return half;
}

ll C(int a, int b) {
    return fac[a] * pw(fac[b], MOD - 2) % MOD * pw(fac[a - b], MOD - 2) % MOD;
}

ll D(int n) {
    return fac[n] * pw(n, MOD - 2) % MOD;
}

int main() {
    for(int i = 1; i < maxN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    for(int i = 1; i < maxN; i++) {
        dp[i] = dp[i - 1] + D(i) * C(i + 1)
    }

    int t = 1;
    cin >> t;
    while(t--) {

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

