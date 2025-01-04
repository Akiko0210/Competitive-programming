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

void solve() {
    int n;
    cin >> n;
    vector dp(100001, 0LL);
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
        dp[x] += x;
    }

    /*
        dp[i] = the max point that you can earn by deleting all the number <= i. -> dp[i - 1]
        dp[3] -> dp[1]
    
    */

    sort(a.begin(), a.end());
    for(int i = 2; i <= 100000; i++) {
        dp[i] += dp[i - 2];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[100000] << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

