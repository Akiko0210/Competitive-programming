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
const int N = 1e5;

vector<vector<int> > divisors(N + 1);

ll pw (ll a, ll b) {
    if(b == 0) return 1;

    ll h = pw(a, b / 2);
    h = h * h % MOD;
    if(b & 1) {
        h = h * a % MOD;
    }

    return h;
}

void solve() {
    int k, n;
    cin >> k >> n;
    vector<vector<int> > dp(k + 1, vector<int> (17, 0));
    dp[1][0] = 1;
    
    for(int i = 2; i <= k; i++) {
        for(int j = 1; j < 17; j++) {
            for(int x : divisors[i]) {
                (dp[i][j] += dp[x][j - 1]) %= MOD;
            }
        }
    }

    vector<ll> mult(18, 1);

    for(int i = 1; i <= 18; i++) {
        if(i > n + 1) break;

        // n + 1 choose i
        for(int j = 1; j <= i; j++) {
            mult[i] = mult[i] * (n + 1 - j + 1) % MOD;
            mult[i] = mult[i] * pw(j, MOD - 2) % MOD;
        }

    }
    
    cout << n << " ";
    for(int i = 2; i <= k; i++) {
        ll ans = 0;
        for(int j = 0; j < min(17, n + 1); j++) {
            (ans += (ll)dp[i][j] * mult[j + 1] % MOD) %= MOD;
        }
        cout << ans << " ";
    }
    cout << "\n";

}

int main() {
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                divisors[i].pb(j);
                if(i / j != j && j > 1)
                    divisors[i].pb(i / j);
            }
        }
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

