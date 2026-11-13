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

int main() {
    int n, m;
    cin >> n >> m;
    int maxmask = (1 << n);
    vector<int> dp(maxmask, 0);
    dp[maxmask - 1] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            vector<int> nxtdp(maxmask, 0);
            for(int mask = 0; mask < maxmask; mask++) {
                if(mask & (1 << (n - 1))) {
                    // (i, j) is left empty
                    int nxtmask = (mask << 1) & (maxmask - 1);
                    (nxtdp[nxtmask] += dp[mask]) %= MOD;

                    // horizontal
                    if(j > 0 && (mask & 1) == 0) {
                        nxtmask = (mask << 1) & (maxmask - 1);
                        (nxtdp[nxtmask | 3] += dp[mask]) %= MOD;
                    }
                } else {
                    // vertical placement.
                    int nxtmask = (mask << 1) & (maxmask - 1);
                    (nxtdp[nxtmask | 1] += dp[mask]) %= MOD;
                }
            }

            dp = nxtdp;
            // for(int mask = 0; mask < maxmask; mask++) {
            //     bitset<4> bitmask(mask);
            //     cout << bitmask << " " << dp[mask] << "\n";
            // }
            // cout << "\n";
        }
    }

    cout << dp[maxmask - 1] << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

