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

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<ll> > dp(n + 1, vector<ll> (k + 1, 0));
    ll ans = 0;
   
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (i == 0 ? 0 : dp[i - 1][0]) + a[i] - x;
        dp[i][0] = max(0LL, dp[i][0]);
        if(k <= n - i) 
            ans = max(dp[i][0], ans);
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min((int)k, i); j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + x);
            if(i > j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] - x);

            dp[i][j] = max(dp[i][j], 0LL);
            if(k - j <= n - i)
                ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
}

int main() {
    int t;
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
