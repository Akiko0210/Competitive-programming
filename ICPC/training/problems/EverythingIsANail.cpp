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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // fixed tool ordering -> 6 different. 
    vector<int> tools = {0, 1, 2};
    int ans = 0;
    do {
        // dp[i][j] = when j-th tool in hand, at i, what's max tasks we can complete?
        vector<vector<int> > dp(n + 1, vector<int> (3, 0));
        for(int i = 0; i < n; i++) {
            int mx = 0;
            for(int j = 0; j < 3; j++) {
                mx = max(mx, dp[i][j]);
                dp[i + 1][j] = mx + (a[i] == tools[j]);
            }
        }
        for(int j = 0; j < 3; j++) {
            ans = max(ans, dp[n][j]);
        }
    } while(next_permutation(tools.begin(), tools.end()));
    
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

