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
    int r, c, p;
    cin >> r >> c >> p;
    vector<vector<double> > dp(r + 1, vector<double> (c + 1, 1e18));
    dp[1][1] = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(i == 1 && j == 1) continue;

            
            double top = (j == c ? (double) p / 2 : (double)p / 4) + dp[i - 1][j];
            double left = (i == r ? (double) p / 2 : (double)p / 4) + dp[i][j - 1];
            if((i - 1) - j == r - c) {
                top = dp[i - 1][j];
            } 
            if(i - (j - 1) == r - c) {
                left = dp[i][j - 1];
            }
            dp[i][j] = min(top, left);
        }
    }
    cout << dp[r][c] << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

