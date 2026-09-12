// Need to revisit one day.

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
    vector<int> a(n), maxL(n, -1);
    vector<int> banned(n + 2, false);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // from a[i] * (i + 1) to (a[i] + 1) * (i + 1) - 1 should be blocked.
        // batches of i
        int l = min(n, a[i] * (i + 1)), r = min(n, (a[i] + 1) * (i + 1));
        banned[l]++;
        banned[r]--;

        // for every R, find max L
        for(int j = 0; j < a[i]; j++) {
            l = min(n - 1, (i + 1) * j);
            r = min(n - 1, (i + 1) * (j + 1) - 1);
            maxL[r] = max(maxL[r], l);
            // debug(r, l, i + 1, maxL[r]);
        }
    }

    for(int i = 1; i <= n; i++) {
        // cout << maxL[i] << " ";
        banned[i] += banned[i - 1];
    }


    // 
    vector<int> dp(n + 1);
    dp[0] = 1;
    ll total = 1, pointer = 0;
    for(int i = 0; i < n; i++) {
        if(banned[i] == 0) {
            // it's okay to take i.
            dp[i + 1] = total;
            (total += dp[i + 1]) %= MOD;
        }

        // ll invalid = (maxL[i] >= 0 ? dp[maxL[i]] : 0);
        // total -= invalid;
        if(maxL[i] >= 0) {
            while(pointer <= maxL[i]) {
                total = (total - dp[pointer] + MOD) % MOD;
                pointer++;
            }
        }
    }
    cout << total << "\n";
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

