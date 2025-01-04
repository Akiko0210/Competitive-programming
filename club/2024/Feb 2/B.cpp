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

int dp[1000001];

int main() {
    // memset(dp, 1000000000, sizeof(dp));
    for(int i = 0; i < 1000001; i++) {
        dp[i] = 1e9;
    }
    int n, x;
    cin >> n >> x;
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << "\n";
    // }
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int y : a) {
        dp[y] = 1;
        for(int j = y + 1; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - y] + 1);
        }
    }

    cout << (dp[x] == 1000000000 ? -1 : dp[x]) << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

