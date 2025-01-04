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
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<pair<int, int> > dp(1 << n, {n, n});
    dp[0] = {1, 0};
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;

            int new_mask = mask | (1 << i);
            int cnt = dp[mask].first, space = dp[mask].second;
            if(space + w[i] > x) {
                space = w[i];
                cnt++;
            } else {
                space += w[i];
            }

            if(dp[new_mask].first > cnt || (dp[new_mask].first == cnt && dp[new_mask].second > space)) {
                dp[new_mask] = {cnt, space};
            }
        }
    }

    cout << dp[(1 << n) - 1].first << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

