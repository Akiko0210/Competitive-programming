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

const ll MOD = 998244353;

vector<ll> fac(2e5 + 1, 1);

ll pow(ll x, ll y) {
    if(y == 1) return x;

    ll m = pow(x, y / 2);
    (m *= m) %= MOD;
    if(y & 1) {
        (m *= x) %= MOD;
    }
    return m;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), cur = 1;
    ll ans = 0, comb = 1, combsum = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            if(cur > 1) {
                combsum += cur - 1;
                (comb *= fac[combsum] * pow(fac[cur - 1], MOD - 2) % MOD * pow(fac[combsum - cur + 1], MOD - 2) % MOD * fac[cur] % MOD) %= MOD;
            }
            ans += cur - 1;
            cur = 1;
        } else {
            cur++;
        }
    }
    if(cur > 1) {
        combsum += cur - 1;
        (comb *= fac[combsum] * pow(fac[cur - 1], MOD - 2) % MOD * pow(fac[combsum - cur + 1], MOD - 2) % MOD * fac[cur] % MOD) %= MOD;
    }
    ans += cur - 1;
    cout << ans << " " << comb << "\n";
}

int main() {
    // fac[1] = 1;
    for(int i = 2; i <= 2e5; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

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
