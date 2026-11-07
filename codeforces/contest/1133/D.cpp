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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> has(n * 3 + 1, false);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        has[a[i]] = true;
    }

    ll ans = ((ll)n + (ll)n * (n - 1) / 2) % MOD;
    vector<ll> dp(8, 0);

    for(int i = 1; i <= n * 3; i++) {
        vector<ll> newdp(8, 0);
        if(has[i]) {
            (ans += dp[3] + dp[5] + dp[6]) %= MOD;
            for(int j = 2; j < 7; j++) {
                newdp[(j >> 1) ^ 4] += dp[j];
            }
            newdp[4]++;
        }
        for(int j = 2; j < 8; j++) {
            (newdp[(j >> 1)] += dp[j]) %= MOD;
        }

        for(int j = 0; j < 3; j++) {
            newdp[1 << j] = min(newdp[1 << j], 1LL);
        }
        dp = newdp;
        // cout << "i = " << i << ", ans = " << ans << "\n";
        // for(int j = 0; j < 8; j++) {
        //     cout << dp[j] << " ";
        // }
        // cout << "\n";
    }

    cout << ans << "\n";

    /*
        element x in S is stable if EXACTLY 2 of {x + 1, x + 2, x + 3} are in S.
        S is balanced if AT MOST 2 elements are unbalanced

        given A, 
        count the number of balanced subsets of A.

        patterns
        1 3 4 
    */


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

