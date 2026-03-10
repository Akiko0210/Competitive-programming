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
    int n, sum = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }

    // unordered_map<int, int> dp;
    vector<int> dp(sum + 1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        vector<int> nxt(sum + 1, INF);
        for(int bsum = 0; bsum <= sum; bsum++) {
            if(bsum + b[i] <= sum) {
                nxt[bsum + b[i]] = min(nxt[bsum + b[i]], dp[bsum]);
            }
            nxt[bsum] = min(nxt[bsum], dp[bsum] + a[i]);
        }
        dp = nxt;
    }

    int ans = INF;
    for(int bsum = 0; bsum <= sum; bsum++) {
        ans = min(ans, max(bsum, dp[bsum]));
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

