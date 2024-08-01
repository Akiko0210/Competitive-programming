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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    // vector<vector<int> > a(n, vector<int> (m));
    vector<ll> res(n);
    for(int i = 0; i < n; i++) {
        vector<ll> dp(m, 0);
        multiset<ll> s;
        s.insert(1);
        dp[0] = 1;
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if(j > 0) {
                dp[j] = *s.begin() + x + 1;
                s.insert(dp[j]);
            }
            if(j > d) s.erase(s.find(dp[j - d - 1]));
            // cout << dp[j] << " ";
        }
        // cout << "\n";
        res[i] = dp[m - 1];
    }
    ll ans = INT64_MAX, sum = 0;
    for(int i = 0; i < n; i++) {
        // debug(i, res[i]);
        sum += res[i];
        if(i >= k - 1) {
            ans = min(ans, sum);
            sum -= res[i - k + 1];
        }
        
    }
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

