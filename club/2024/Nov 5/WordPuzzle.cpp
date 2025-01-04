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

    /*
    programming
     _ __     _
    rgg


    First idea:
    - if we didn't have to deal with loops, we could've 
      have dp which 
      dp[i][j] = pos of (at i, covered first j).

    - but loops makes this idea wrong. 

    How to deal with the loops? 
    Given 11 seconds.
    We can have 2 different dps. 
    dp[i][j]: from 0 to i, last j chars are covered.
    dp1[i][j]: from i to n, first j chars are covered.

    ans = sum(dp[i][j from 0 to m] * dp1[i + 1][m - j])

    both dp requires N * m^2 = 2500 * 10^5 = 2.5 10^8

    How to build my dp?
    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (s[i] == t[m - j - 1])
    

    */
    

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

