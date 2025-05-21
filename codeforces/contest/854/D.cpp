#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF 1e15
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
    int n, k;
    cin >> n >> k;
    vector<int> hot(k + 1), cold(k + 1), a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int i = 1; i <= k; i++) 
        cin >> cold[i];
    
    for(int i = 1; i <= k; i++) 
        cin >> hot[i];

    vector<vector<ll> > dp(k + 1, vector<ll> (k + 1, INF));
    // for(int i = 1; i <= k; i++) {
    //     dp[a[0]][i] = cold[a[0]];
    //     dp[i][a[0]] = cold[a[0]];
    // }

    dp[a[0]][0] = cold[a[0]];
    dp[0][a[0]] = cold[a[0]];


    for(int i = 1; i < n; i++) {
        vector<ll> x;
        for(int j = 0; j <= k; j++) {
            x.pb(dp[a[i - 1]][j]);
        }
        for(int j = 0; j <= k; j++) {
            dp[a[i]][j] = dp[a[i]][a[i - 1]] = INF;
        }
        for(int j = 0; j <= k; j++) {
            if(x[j] == INF) {
                continue;
            }

            dp[a[i]][j] = min(dp[a[i]][j], x[j] + (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]));
            dp[a[i]][a[i - 1]] = min(dp[a[i]][a[i - 1]], x[j] + ((a[i] == j) ? hot[a[i]] : cold[a[i]]));
        }
    }

    ll ans = INF;

    for(int i = 0; i <= k; i++) {
        // if(dp[i][a[n - 1]] == 0 && dp[a[n - 1]][i] == 0) continue;
        // textcolor(RED);
        debug(i);
        ans = min(ans, dp[a[n - 1]][i]);
    }
    
    cout << ans << "\n";


    /*
        dp[i][j] = dp[k][j] + (i == k ? hot[i] : cold[i]);

    */


}

int main() {
    FAST
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
