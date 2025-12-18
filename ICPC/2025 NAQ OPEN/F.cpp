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
    int n, t, k, ans = 0;
    cin >> n >> t >> k;
    /*
    leaving k, what's the max non-overlapping segment you can include. 
    */

    vector<vector<int> > dp(n + 1, vector<int> (n + 1, -2e9));
    vector<pii> a(n + 1);
    a[0] = {0, 0};
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].ss >> a[i].ff;
    }

    sort(a.begin(), a.end());
    for(int i = 0; i <= n; i++) {
        dp[i][0] = a[i].ff;
    }

    for(int i = 1; i <= n; i++) {
        pii temp = {a[i].ss, a[i].ss};
        int prevind = upper_bound(a.begin(), a.end(), temp) - a.begin() - 1;
        for(int j = 1; j <= i; j++) {
            if(dp[prevind][j - 1] == -2e9 && dp[i - 1][j] == -2e9) continue;
            if(dp[prevind][j - 1] == -2e9) {
                // only way to come is from top.
                dp[i][j] = dp[i - 1][j] + (a[i].ff - a[i - 1].ff);
            } else {
                int dis = a[i].ss - a[prevind].ff;
                if(dp[i - 1][j] + (a[i].ff - a[i - 1].ff) >= dp[prevind][j - 1] + dis) {
                    dp[i][j] = dp[i - 1][j] + (a[i].ff - a[i - 1].ff);
                } else {
                    dp[i][j] = dp[prevind][j - 1] + dis;
                }
            }
            if(dp[i][j] + (t - a[i].ff) >= k && j > ans) {
                ans = j;
            }
        }
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

