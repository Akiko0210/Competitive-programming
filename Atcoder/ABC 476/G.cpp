#include <bits/stdc++.h>
#include <bit>
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

long long choose[61][61];

void solve() {
    ull L, R;
    cin >> L >> R;

    // find the blocks.
    // only the base bit count and allowed bit counts matter.
    // {base, range} -> 
    vector<pii> blocks;
    while (L <= R) {
        int mx = 0;
        while(L % (1LL << mx) == 0 && (L + (1LL << mx) - 1) <= R) {
            mx++;
        }
        mx--;
        blocks.pb({popcount(L), mx});
        // debug(L, mx);
        L += (1LL << mx);
    }

    vector<ll> dp(61, 0);
    // dp[i] = max len with last has i popcnt.
    for(auto [base, mx] : blocks) {
        for(int i = mx; i >= 0; i--) {
            dp[base + i] += choose[mx][i];
        }

        for(int i = 60; i > 0; i--) {
            dp[i - 1] = max(dp[i - 1], dp[i]);
        }
    }

    cout << dp[0] << "\n";
}

int main() {
    choose[0][0] = 1;
    for(int i = 1; i <= 60; i++) {
        choose[i][0] = 1;
        choose[i][i] = 1;
        for(int j = 1; j < i; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
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

